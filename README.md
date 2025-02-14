# so_long

**so_long** is a 2D game project for [42Lausanne](https://www.42lausanne.ch/) (42 Network). In this game, the main character (a guy sweeping the floor) must collect all the "42" coins to power on a computer and become a programmer.

## Overview

In **so_long**, your objective is to:
- **Collect all coins** (collectibles) on the map.
- **Reach the exit** once all coins have been collected.
- Navigate through a rectangular map with walls, collectibles, an exit, and a starting position.

The map is provided in a file with a `.ber` extension. It must follow these rules:
- **Characters used:**
  - `0`: Empty space
  - `1`: Wall
  - `C`: Collectible (coin)
  - `E`: Exit
  - `P`: Starting position
- The map must be rectangular, completely enclosed by walls, contain exactly one exit, at least one collectible, and one starting position.
- The game also verifies that there is a valid path from the starting position to all collectibles and to the exit.

## How to Play

- **Objective:** Collect all the coins and then exit the level.
- **Movement:**  
  Use **WASD** keys or **arrow keys**.
  - **WASD (Linux codes):**  
    - `W`: 119  
    - `A`: 97  
    - `S`: 115  
    - `D`: 100  
  - **Arrow Keys (Linux codes):**  
    - Up: 65362  
    - Down: 65364  
    - Left: 65361  
    - Right: 65363
- Each move updates a movement counter printed in the terminal.
- The player cannot move through walls.

## Graphics and Libraries

The game uses **MinilibX** for window creation and image rendering. Custom textures are used for the walls, floor, coins, exit, and the main character. Instead of the originally suggested theme (a dolphin, fish, and Earth), the game features a guy sweeping the floor and coins labeled "42."

### External Tools

The following programs were used for image generation and editing:
- **Adobe Stock:** Surface textures.
- **Ideogram:** Item generation.
- **GIMP:** Image editing.
- **ImageMagic:** Format conversion.

### Reused Libraries

This project leverages previous work and includes:
- **libft**
- **ft_printf**
- **get_next_line**

## Compilation & Execution

### Compiling the Project

The project includes a `Makefile` that compiles all source files and links the necessary libraries. To compile, simply run:

```bash
make
