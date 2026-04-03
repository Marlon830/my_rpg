# My RPG

A top-down 2D RPG written in C using CSFML, featuring turn-based grid combat, NPC dialogue, equipment progression, and a save system.

---

## Features

- **World exploration** across several interconnected maps (forest, city, dungeons, basement, boat, and more)
- **Turn-based grid combat** on a tile map with a card-based ability system in isometric view
- **Equipment system** with 8 gear slots (helmet, armor, pants, boots, amulet, ring, sword, shield), each providing stat bonuses
- **Quest tracking** with active and completed quest states
- **NPC dialogue** system with portraits and branching conversations
- **Save / Load** full game state persisted to a local save file
- **Settings** volume control and fullscreen toggle

---

## Requirements

- GCC
- CSFML 2.5+ (`libcsfml-graphics`, `libcsfml-window`, `libcsfml-system`, `libcsfml-audio`)

On Debian/Ubuntu:
```bash
sudo apt install libcsfml-dev
```

On Arch Linux:
```bash
sudo pacman -S csfml
```

---

## Build & Run

```bash
make        # Compile → produces ./my_rpg
./my_rpg    # Launch the game
```

Other build targets:

```bash
make re      # Clean rebuild
make clean   # Remove object files
make fclean  # Remove object files and binary
```

---

## How to Play

| Key / Action | Description |
|---|---|
| Arrow keys / ZQSD | Move the player |
| E / Enter | Interact with NPCs and objects |
| Tab | Open inventory |
| Escape | Pause menu |

In combat, select cards from your hand to cast abilities, then click tiles to move or attack within range.
