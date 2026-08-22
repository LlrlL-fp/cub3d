# cub3d

*This project was created as part of the 42 curriculum by lren and malmany.*

## Description

`cub3D` is a 42 project inspired by Wolfenstein 3D. It uses raycasting to
display a pseudo-3D view from a 2D map.

### Parsing

The parser reads and validates the `.cub` scene file before starting the game.
It checks:

- the four wall textures: `NO`, `SO`, `WE` and `EA`;
- the floor (`F`) and ceiling (`C`) colors;
- the presence of one player and its orientation: `N`, `S`, `E` or `O`;
- that the map is closed by walls;
- allowed characters and inaccessible spaces.

### Raycasting

For every screen column, a ray is cast from the player's position. The engine
uses DDA (Digital Differential Analyzer) to find the first wall hit by the ray
and calculate its perpendicular distance. This distance determines the wall
height on screen. The hit side and impact position are then used to select the
wall texture and the texture pixel to draw for each row of the column.

## Instructions

### Requirements

From the project root, clone the official MiniLibX version into the directory
expected by the Makefile. This version is compatible with Fedora:

```bash
git clone https://github.com/42paris/minilibx-linux.git minilibx-linux
```

### Compilation

Compile the project with:

```bash
make
```

To remove object files and rebuild everything:

```bash
make re
```

### Execution

The program expects one `.cub` scene file:

```bash
./cub3d path/to/map.cub
```

Example:

```bash
./cub3d t.cub
```

Controls:

- `W` / `S`: move forward / backward;
- `A` / `D`: move left / right;
- left / right arrow keys: rotate;
- `ESC`: exit the program.

### Minimal `.cub` file format

```text
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm

F 123,45,22
C 1,2,254

111111
100001
10N001
100001
111111
```

## Resources

