# 🎮 SFML Projects

A collection of C++/SFML projects for learning computer graphics, game engine architecture, and preparing for OpenGL/Vulkan.

## 🎯 Goal
This repository is my path from 2D games to graphics programming. Each project solves a specific problem: renderer architecture, transformation mathematics, vertex buffer management, or understanding the graphics pipeline.
## 📁 Repository Structure
sfml-projects
  1. pong # Pong — OOP, collisions, game states
  2. timber # Timber — sprites, game loop
  3. asteroids # Asteroids — inheritance, polymorphism
  4. raycaster # Pseudo-3D (Wolfenstein 3D) — DDA, vectors
  5. cube-spin # 3D Cube Spin — 4×4 matrices from scratch
  6. software-rasterizer # CPU Rasterizer — barycentrics, z-buffer
  7. README.md

Each project includes its own `CMakeLists.txt` and `Makefile`.
## 🛠️ Tech Stack

| Component    | Technology                              |
| ------------ | --------------------------------------- |
| Language     | C++17                                   |
| Graphics     | SFML 3.0                                |
| Build system | CMake / Make                            |
| Compiler     | Clang (Linux)                           |
| Math         | Custom vector and matrix implementation |
## 📊 Progress

| \#    | Project             | Status      | Key Skills                                     |
| ----- | ------------------- | ----------- | ---------------------------------------------- |
| **1** | Pong                | In progress | Classes, encapsulation, collision detection    |
| **2** | Timber              | Pending     | Sprites, textures, game loop                   |
| **3** | Asteroids           | Pending     | Polymorphism, `vector<Entity*>`, sin/cos       |
| **4** | Raycaster           | Pending     | Vectors, DDA algorithm, perspective projection |
| **5** | 3D Cube Spin        | Pending     | 4×4 matrices, Model/View/Projection            |
| **6** | Software Rasterizer | Pending     | Barycentric coordinates, z-buffer, texturing   |
## 🚀 Quick Start

```bash
# Clone the repository
git clone https://github.com/Anohoshi/sfml-projects.git
cd sfml-projects/pong

# Build
# --- CMake ---
cmake -B build
cmake --build build

# Run
./build/Pong 

# --- Make ---
make run
```

**Requirements:**
- C++17 (Clang or GCC)
- SFML 3.0
- CMake 3.16+
## 📚 Next Steps

After completing all projects in this phase — moving on to OpenGL:

- [LearnOpenGL.com](https://learnopengl.com/) — main tutorial
- Boreskov «Computer Graphics Programming» (Russian) — reference
- Lengyel «Mathematics for 3D Game Programming» — advanced math