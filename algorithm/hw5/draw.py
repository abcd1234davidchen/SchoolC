import sys
import math
from pathlib import Path

import imageio.v2 as imageio
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.backends.backend_agg import FigureCanvasAgg


def read_frames(txt_path: Path):
    lines = [ln.strip() for ln in txt_path.read_text().splitlines() if ln.strip()]
    if not lines:
        raise ValueError("Input file is empty")

    # 靜態點（保持不動）
    static_vals = list(map(float, lines[0].split()))
    if len(static_vals) % 2 != 0:
        raise ValueError("Static points line must contain even number of values")
    static_xy = list(zip(static_vals[0::2], static_vals[1::2]))

    # 動畫幀
    frames = []
    for li, line in enumerate(lines[1:], start=2):
        vals = list(map(float, line.split()))
        if len(vals) % 2 != 0:
            raise ValueError(f"Line {li} has odd number of values")
        xy = list(zip(vals[0::2], vals[1::2]))
        frames.append(xy)

    if not frames:
        raise ValueError("No animation frames found")
    return static_xy, frames


def render_gif(static_xy, frames, out_path: Path, fps=15):
    # 計算範圍
    xs_all = [x for x, y in static_xy]
    ys_all = [y for x, y in static_xy]
    for fr in frames:
        xs_all.extend(x for x, y in fr)
        ys_all.extend(y for x, y in fr)
    x_min, x_max = min(xs_all), max(xs_all)
    y_min, y_max = min(ys_all), max(ys_all)
    pad = 0.05 * max(x_max - x_min, y_max - y_min, 1.0)
    x_min -= pad; x_max += pad
    y_min -= pad; y_max += pad

    fig, ax = plt.subplots(figsize=(6, 6), dpi=80)
    ax.set_xlim(x_min, x_max)
    ax.set_ylim(y_min, y_max)
    ax.set_aspect("equal", adjustable="box")
    ax.scatter([p[0] for p in static_xy], [p[1] for p in static_xy],
               c="red", s=20, zorder=3, label="static")
    line, = ax.plot([], [], "b-", lw=1.0, alpha=0.7)
    pts,  = ax.plot([], [], "bo", ms=3, alpha=0.7)
    ax.legend(loc="upper right")

    canvas = FigureCanvasAgg(fig)
    images = []

    # 迭代幀，並在最後補第一幀做無縫 loop
    for fr in frames + [frames[0]]:
        xs = [p[0] for p in fr] + [fr[0][0]]
        ys = [p[1] for p in fr] + [fr[0][1]]
        line.set_data(xs, ys)
        pts.set_data(xs, ys)
        
        canvas.draw()
        renderer = canvas.get_renderer()
        raw_data = renderer.tostring_argb()
        w, h = canvas.get_width_height()
        # ARGB -> RGB
        img = np.frombuffer(raw_data, dtype=np.uint8).reshape(h, w, 4)
        img = img[:, :, 1:]  # 取 RGB，丟掉 A channel
        images.append(img)

    imageio.mimsave(out_path, images, duration=1 / fps, loop=0)
    plt.close(fig)


def np_from_figure(canvas):
    # 轉為 (H, W, 3) uint8
    import numpy as np
    buf = canvas.buffer_rgba()
    w, h = canvas.get_width_height()
    arr = np.frombuffer(buf, dtype=np.uint8).reshape((h, w, 4))
    return arr[:, :, :3]


def main():
    if len(sys.argv) != 3:
        sys.exit(1)
    txt_path = Path(sys.argv[1])
    out_path = Path(sys.argv[2])
    static_xy, frames = read_frames(txt_path)
    render_gif(static_xy, frames, out_path)

if __name__ == "__main__":
    main()