# Console Space Invaders in C++

I created a console-based Space Invaders game in C++. The game lets the player move left and right, shoot bullets at enemies, and avoid enemies reaching the bottom of the screen. It uses simple object-oriented programming (OOP) and vector-based logic to manage the game state.

---

## Features
- Player-controlled spaceship (move left/right, shoot bullets)  
- Enemy aliens that move left/right and descend when hitting screen edges  
- Collision detection for bullets and enemies  
- Win condition when all enemies are destroyed  
- Game-over condition when an enemy reaches the player  
- Simple ASCII-based console display  

---

## Controls
- `A` → Move left  
- `D` → Move right  
- `W` → Shoot bullets  

---

## Technologies Used
- **Language:** C++  
- **Paradigm:** Object-Oriented Programming (OOP)  
- **Tools:** Visual Studio, Git, GitHub  
- **Platform:** Windows Console  

---

## Getting Started

### Requirements
- Windows (for console input/output)  
- C++17 compatible compiler (e.g., Visual Studio or g++)  

### Compilation
```bash
g++ -std=c++17 space_invaders.cpp -o space_invaders
