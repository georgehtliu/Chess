# Chess Game

A full-featured chess implementation in C++ with a graphical interface. Built from scratch to explore game development, AI algorithms, and C++ design patterns.

## Features

- **Complete Chess Rules**: Implements all standard chess rules including castling, en passant, pawn promotion, check, checkmate, and stalemate detection
- **Multiple AI Difficulty Levels**: Three different AI opponents with varying strategies
- **Graphical & Text Interfaces**: Dual display modes with real-time board visualization using X11 graphics
- **Custom Board Setup**: Build and play custom board configurations
- **Flexible Game Modes**: Play human vs human, human vs AI, or watch AI vs AI matches
- **Score Tracking**: Keeps track of wins/losses across multiple games

## Building

```bash
make
```

The executable will be created in the project root as `chess`.

## Usage

### Starting a Game

```
game [white-player] [black-player]
```

Player types:
- `human` - Play as human
- `computer1` - AI level 1 (random legal moves)
- `computer2` - AI level 2 (prefers captures and checks)
- `computer3` - AI level 3 (avoids captures, prefers captures and checks)

### During Gameplay

**As Human:**
- `move e2 e4` - Move from e2 to e4
- `move e7 e8 n` - Promote pawn to knight (defaults to queen if unspecified)
- `resign` - Forfeit the game

**As Computer:**
- `move` - Triggers AI to make its move
- `resign` - Forfeit the game

### Custom Setup

```
setup
```

Enter setup mode to create custom board configurations, then start a game to play with your setup.

### Quit

```
quit
```

Exit the game and view final scores.

## Architecture

The project uses:
- **Observer Pattern**: Text and graphics observers for displaying board state
- **Strategy Pattern**: Different AI implementations with pluggable strategies
- **Modern C++**: Smart pointers, STL containers, and RAII principles

## Project Structure

```
.
├── src/           # Implementation files
├── include/       # Header files
├── assets/        # Piece images and text files
├── tests/         # Test game scenarios
└── doc/           # Design documentation
```

## Future Ideas

- Improved AI using minimax algorithm with alpha-beta pruning
- Network multiplayer support
- Move history and game replay
- PGN import/export for game analysis
- Undo/redo functionality
