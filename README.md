# so_long

**so_long** is a 2D game project for [42Lausanne](https://www.42lausanne.ch/) (42 Network). In this game, the main character (a guy sweeping the floor) must collect all the "42" coins to power on a computer and become a programmer.

## Overview

In **so_long**, your objective is to:
- **Collect all coins** (collectibles) on the map.
- **Reach the exit** once all coins have been collected.
- Do it in the most efficient way.

The map is provided in `.ber` extension text file. It must follow these rules:
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
    - `W` or `Up`: move up
    - `A` or `Left`: move left  
    - `S` or `Down`: move down   
    - `D` or `Right`: move right 
- Each move updates a movement counter printed in the terminal.
- The player cannot move through walls.

## Graphics and Libraries

The game uses **MinilibX** for window creation and image rendering. Custom textures are used for the walls, floor, coins, exit, and the main character.

### External Tools

The following programs and services were used for image generation and editing:
- **Adobe Stock:** Surface textures.
- **Ideogram:** Item generation.
- **GIMP:** Image editing.
- **ImageMagic:** Format conversion.

### Reused Libraries

This project leverages previous 42 work and includes:
- **libft**
- **ft_printf**
- **get_next_line**

## Compilation & Execution

### Compiling the Project

The project includes a `Makefile` that compiles all source files and links the necessary libraries. To compile, simply run:

```bash
make
```
Then, run the game by passing a .ber map file:
```bash
./so_long path/to/map.ber
```
## Installing and Linking MinilibX
### Linux:

1. Install dependencies:
```bash
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```
2. Clone MinilibX into your project:
```bash
git clone https://github.com/42Paris/minilibx-linux.git mlx
```
The provided Makefile will build MinilibX automatically.

3. Add this includes and flags to your Makefile:
```makefile
# Contains the X11 and MLX header files
INCLUDES = -I/usr/include -Imlx

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
```
### macOS:

Install XQuartz if needed.
Clone MinilibX:
```bash
git clone https://github.com/42Paris/minilibx-linux.git mlx
```
Use this includes and flags in your Makefile:
```makefile
# Contains the X11 and MLX header files
INCLUDES = -I/opt/X11/include -Imlx

MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
```

# License
This project is for educational purposes as part of the 42 Network curriculum.
