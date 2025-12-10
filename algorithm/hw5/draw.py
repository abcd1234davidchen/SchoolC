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
        
    if not xs_all: return

    x_min, x_max = min(xs_all), max(xs_all)
    y_min, y_max = min(ys_all), max(ys_all)
    pad = 0.05 * max(x_max - x_min, y_max - y_min, 1.0)
    x_min -= pad; x_max += pad
    y_min -= pad; y_max += pad

    fig, ax = plt.subplots(figsize=(6, 6), dpi=80)
    
    # Pre-configure plot settings
    canvas = FigureCanvasAgg(fig)
    
    images = []

    for i, fr in enumerate(frames):
        ax.clear()
        ax.set_xlim(x_min, x_max)
        ax.set_ylim(y_min, y_max)
        ax.set_aspect("equal", adjustable="box")
        
        # 1. Draw Static Cities (Red)
        ax.scatter([p[0] for p in static_xy], [p[1] for p in static_xy],
                   c="red", s=20, zorder=3, label="static")
        
        # 2. Draw Dynamic Path (Blue)
        # Close loop visually by appending start point to end
        xs = [p[0] for p in fr] + [fr[0][0]]
        ys = [p[1] for p in fr] + [fr[0][1]]
        
        ax.plot(xs, ys, "b-", lw=1.0, alpha=0.7)
        ax.plot(xs, ys, "bo", ms=3, alpha=0.7)
        
        # Remove legend to save space/clutter if desired, or keep it
        # ax.legend(loc="upper right")
        
        canvas.draw()
        renderer = canvas.get_renderer()
        raw_data = renderer.tostring_argb()
        w, h = canvas.get_width_height()
        img = np.frombuffer(raw_data, dtype=np.uint8).reshape(h, w, 4)
        images.append(img[:, :, 1:]) # RGB

    # --- FORCE PAUSE BY DUPLICATION ---
    # Instead of setting duration, we copy the last frame N times
    # 2.0 seconds * 15 fps = 30 copies
    copies = int(pause_seconds * fps)
    last_img = images[-1]
    for _ in range(copies):
        images.append(last_img)

    # --- LOOP BACK ---
    # Add the first frame at the very end to smooth the loop
    images.append(images[0])

    # Use standard duration for all frames
    imageio.mimsave(out_path, images, fps=fps, loop=0)
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