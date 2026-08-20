# so_long

A small tile-based game written in C with MiniLibX for the School 21 curriculum.

The player explores a validated map, collects every objective, avoids moving enemies, and reaches the exit. The repository includes custom sprites, animation, bonus enemy behavior, and several playable maps.

## Features

- rectangular `.ber` map parsing and validation;
- reachability and boundary checks;
- keyboard movement with collision handling;
- collectibles, exit state, enemies, and animation;
- move counting and clean shutdown;
- strict C build flags: `-Wall -Wextra -Werror`.

## Build and run

The included Makefile targets macOS and links MiniLibX through OpenGL and AppKit.

```bash
make
./so_long maps/map_bonus.ber
```

Or use the convenience target:

```bash
make run
```

## Controls

| Action | Key |
| --- | --- |
| Move | `W` `A` `S` `D` or arrow keys |
| Exit | `Esc` |

## Map format

Maps use a simple grid representation: walls, floor, one player start, at least one collectible, and one exit. Invalid or unreachable layouts are rejected before the game starts.

## Project status

Learning project preserved as part of my School 21 portfolio. Generated object files and compiled binaries should be removed in a future cleanup commit.
