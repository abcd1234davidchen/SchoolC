import sys
import imageio.v2 as imageio
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.backends.backend_agg import FigureCanvasAgg
from pathlib import Path

def read_frames(txt_path: Path):
    content = txt_path.read_text(encoding='utf-8')
    lines = [ln.strip() for ln in content.splitlines() if ln.strip()]
    
    if not lines:
        raise ValueError("Input file is empty")

    # Line 1: Static points (Cities)
    static_vals = list(map(float, lines[0].split()))
    static_xy = list(zip(static_vals[0::2], static_vals[1::2]))

    # Lines 2+: Animation frames
    frames = []
    for li, line in enumerate(lines[1:], start=2):
        vals = list(map(float, line.split()))
        xy = list(zip(vals[0::2], vals[1::2]))
        frames.append(xy)

    if not frames:
        raise ValueError("No animation frames found")
    return static_xy, frames

def render_gif(static_xy, frames, out_path: Path, fps=15, pause_seconds=2.0):
    # Calculate bounds
    xs_all = [x for x, y in static_xy]
    ys_all = [y for x, y in static_xy]
    for fr in frames:
        xs_all.extend(x for x, y in fr)
        ys_all.extend(y for x, y in fr)
        
    if not xs_all:
        return

    x_min, x_max = min(xs_all), max(xs_all)
    y_min, y_max = min(ys_all), max(ys_all)
    pad = 0.05 * max(x_max - x_min, y_max - y_min, 1.0)
    x_min -= pad; x_max += pad
    y_min -= pad; y_max += pad

    fig, ax = plt.subplots(figsize=(6, 6), dpi=80)
    canvas = FigureCanvasAgg(fig)

    # Configure static plot once
    ax.set_xlim(x_min, x_max)
    ax.set_ylim(y_min, y_max)
    ax.set_aspect("equal", adjustable="box")
    static_x = [p[0] for p in static_xy]
    static_y = [p[1] for p in static_xy]
    ax.scatter(static_x, static_y, c="red", s=20, zorder=3, label="static")

    # Pre-create dynamic artists and avoid clearing axes each frame
    line, = ax.plot([], [], "b-", lw=1.0, alpha=0.7)
    pts, = ax.plot([], [], "bo", ms=3, alpha=0.7, linestyle="None")

    # Prepare writer to stream frames to disk (reduces memory)
    copies = int(pause_seconds * fps)
    canvas.draw()
    w, h = canvas.get_width_height()

    import imageio
    with imageio.get_writer(out_path, mode='I', fps=fps, loop=0) as writer:
        first_frame_rgb = None
        last_frame_rgb = None

        for i, fr in enumerate(frames):
            arr = np.asarray(fr)
            if arr.size == 0:
                xs_closed = np.array([])
                ys_closed = np.array([])
                xs_pts = ys_pts = np.array([])
            else:
                xs_pts = arr[:, 0]
                ys_pts = arr[:, 1]
                # close loop visually
                xs_closed = np.concatenate([xs_pts, xs_pts[:1]])
                ys_closed = np.concatenate([ys_pts, ys_pts[:1]])

            line.set_data(xs_closed, ys_closed)
            pts.set_data(xs_pts, ys_pts)

            canvas.draw()
            raw = canvas.tostring_argb()
            img = np.frombuffer(raw, dtype=np.uint8).reshape(h, w, 4)
            rgb = img[:, :, 1:]  # RGB

            if i == 0:
                first_frame_rgb = rgb
            last_frame_rgb = rgb
            writer.append_data(rgb)

        # Pause by duplicating last frame
        if last_frame_rgb is not None:
            for _ in range(copies):
                writer.append_data(last_frame_rgb)
        # Loop back smoothly by appending first frame
        if first_frame_rgb is not None:
            writer.append_data(first_frame_rgb)

    plt.close(fig)

def main():
    if len(sys.argv) != 3:
        print("Usage: python draw.py <input_txt> <output_gif>")
        sys.exit(1)
    
    txt_path = Path(sys.argv[1])
    out_path = Path(sys.argv[2])
    
    try:
        static_xy, frames = read_frames(txt_path)
        render_gif(static_xy, frames, out_path)
    except Exception as e:
        print(f"Error: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()