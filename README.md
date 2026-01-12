# ASCII Rotating Pyramid Renderer (C++)

A terminal-based 3D graphics experiment written in **C++** that renders a **rotating 3D pyramid using ASCII characters**. The project demonstrates core computer graphics concepts such as 3D rotation, perspective projection, depth buffering (Z-buffer), and real-time animation — all without any external graphics libraries.

---

## ✨ Features

* Real-time **3D rotation** using Euler angles
* **Perspective projection** from 3D to 2D screen space
* **Z-buffer** for proper depth handling
* Fully **ASCII-rendered** output in the terminal
* No graphics APIs (OpenGL, Vulkan, etc.) — pure math and C++
* Infinite animation loop with smooth updates

---

## 🧠 How It Works (High Level)

1. The pyramid is defined mathematically using its height and base width
2. Each frame:

   * The screen buffer and Z-buffer are cleared
   * Pyramid surface points are generated
   * Each point is rotated in 3D space
   * Points are projected onto a 2D terminal grid
   * The Z-buffer ensures correct visibility
3. The terminal is refreshed using ANSI escape codes
4. Rotation angles are updated continuously

---

## 🖥️ Demo Preview

The output looks like a rotating 3D pyramid made of characters such as:

```
; ! & %
```

Each character represents a different face of the pyramid, helping visualize depth and orientation.

---

## 🛠️ Requirements

* C++ compiler with **C++11 or later** support
* A terminal that supports **ANSI escape sequences**

  * Linux / macOS terminals work best
  * Windows Terminal or recent versions of PowerShell also work

---

## 🚀 Build & Run

### Compile

```bash
g++ -std=c++11 -O2 pyramid.cpp -o pyramid
```

### Run

```bash
./pyramid
```

> Press **Ctrl + C** to stop the animation.

---

## 📁 Project Structure

```
.
├── pyramid.cpp   # Main source file
└── README.md     # Project documentation
```

---

## 📐 Key Concepts Demonstrated

* 3D coordinate transformations
* Rotation matrices (via trigonometry)
* Perspective projection
* Depth testing (Z-buffering)
* Double buffering (manual screen buffer)
* Terminal control using ANSI escape codes

---

## 🎯 Customization Ideas

* Change pyramid size or shape
* Adjust rotation speed or axes
* Add lighting using ASCII shading
* Render different 3D objects (cube, sphere, cone)
* Add frame rate control

---

## 📚 Inspiration

This project is inspired by classic **ASCII 3D demos** and educational renderers that show how graphics work at a low level — similar in spirit to the famous ASCII donut.

---

## 📜 License

This project is released under the **MIT License**. Feel free to modify, learn from, and share it.

---

Happy hacking and welcome to the world of software rendering 🚀
