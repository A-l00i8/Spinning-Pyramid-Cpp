# ASCII Rotating Pyramid Renderer (C++)

A terminal-based **software renderer** written in modern **C++** that displays a rotating 3D pyramid using only ASCII characters. This project was refactored to better reflect **real-world C++ practices**, with clearer structure, safer math, and cleaner state handling.

---

## ✨ What This Project Demonstrates

* Manual **3D rotation** using Euler angles
* **Perspective projection** (3D → 2D)
* **Z-buffer depth testing** for correct visibility
* Real-time animation loop in the terminal
* Clean separation of global configuration vs logic
* No graphics libraries — pure math + C++

---

## 🧠 Key Improvements (Refactor Highlights)

* Added **clear comments** explaining every rendering step
* Reduced unnecessary global state usage
* Fixed array vs pointer linkage issues using correct `extern` declarations
* Made math temporaries local to avoid shared mutable state
* Improved readability and maintainability

These changes make the code closer to what you would expect in a **junior systems / graphics-oriented C++ role**.

---

## 🖥️ How It Works (High Level)

1. A pyramid is described mathematically using height and base width
2. For every animation frame:

   * Screen buffer and Z-buffer are cleared
   * Pyramid surface points are generated
   * Each point is rotated in 3D space
   * Points are projected onto a 2D terminal grid
   * The Z-buffer ensures correct depth ordering
3. ANSI escape codes clear and redraw the terminal
4. Rotation angles are updated continuously

---

## 📂 Project Structure

```
.
├── main.cpp        # Rendering loop and math logic
├── Globals.h       # Shared configuration & state declarations
├── Globals.cpp     # Global definitions (single translation unit)
└── README.md
```

---

## 🚀 Build & Run

### Compile

```bash
g++ -std=c++11 -O2 main.cpp Globals.cpp -o pyramid
```

### Run

```bash
./pyramid
```

Press **Ctrl + C** to exit.

---

## 📐 Concepts You Can Talk About in Interviews

* Perspective projection and camera distance
* Why Z-buffering is necessary
* Difference between arrays and pointers in C++ linkage
* Translation units and the One Definition Rule (ODR)
* Why global mutable state is dangerous and how to reduce it

---

## 🎯 Possible Extensions

* Add ASCII lighting / shading
* Add keyboard input for camera control
* Implement FPS limiting and timing
* Support multiple 3D objects (cube, sphere)
* Wrap renderer logic into a class

---

## 📜 License

MIT License — free to learn from, modify, and share.

---

This project is intentionally low-level to **show understanding**, not visual fidelity. It’s meant to answer the question:

> *"How does rendering actually work under the hood?"*

And it does so — in plain C++.
