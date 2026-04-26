# cub3D

![Score](https://img.shields.io/badge/score-125%2F100-success)
![C](https://img.shields.io/badge/language-C-blue)
![Graphics](https://img.shields.io/badge/concept-Raycasting-orange)

## 📌 Overview
**cub3D** is a graphics project at 1337 (42 Network) inspired by the legendary game Wolfenstein 3D. The objective is to create a dynamic 3D view inside a maze using the mathematical technique known as Raycasting.

This project represents a significant leap in algorithmic complexity. As a Software Engineer, this project showcases my ability to implement complex mathematics, handle real-time rendering, and manage application performance.

## 💡 Core Concepts Explored
### Raycasting
**Definition:** Raycasting is a rendering technique to create a 3D perspective in a 2D map. It works by tracing rays from the player's viewpoint and calculating intersections with walls.
**Problem Solved:** It solves the problem of rendering complex 3D environments efficiently on limited hardware by simplifying the 3D projection mathematical calculations into 2D plane intersection checks.

## 🚀 Features
- **Raycasting Engine:** Calculates distance to walls and renders a pseudo-3D environment using untextured or textured vertical slices.
- **Map Parsing:** Strictly parses `.cub` configuration files for textures, floor/ceiling colors, and the map grid.
- **Textures:** Applies custom textures to North, South, East, and West walls.
- **Movement:** Implements smooth player movement and rotation, complete with collision detection.
- **Minimap (Bonus):** Renders a 2D overhead map to show the player's position.

## 📥 How to Clone
To clone this project, use the following command:
```bash
git clone git@github.com:Anasqabbal/cub3D.git
cd cub3D
```

## 🛠️ Usage
Compile the engine:
```bash
make
```
Run the game with a map using the generated `cub3D` executable:
```bash
./cub3D maps/map.cub
```

## 🧠 What I Learned
- In-depth understanding of trigonometry and linear algebra as applied to computer graphics.
- Real-time rendering optimization techniques.
- Advanced parsing of complex configuration files.
- Managing a complex graphical state machine in C.

## 🌐 Connect with me
[![GitHub](https://img.shields.io/badge/GitHub-black?logo=github)](https://github.com/Anasqabbal)
[![LinkedIn](https://img.shields.io/badge/-IN-0A66C2?logo=linkedin&logoColor=0a66c2)](https://www.linkedin.com/in/anasqabbal/)

