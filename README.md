# C++ Blackjack

A single-player Blackjack game I built for my Computer Science I course. The player competes against the dealer using a starting balance, places bets, and tries to beat the saved high score.

## Features

- Hit, stand, and double down.
- Dealer draws until its hand reaches at least 17.
- Aces can count as 1 or 11.
- Rules available from the game menu.
- High score saved between sessions.

## Skills Practiced

C++ functions, loops, conditionals, vectors, input validation, random numbers, and reading and writing text files.

## How to Run

You need a C++ compiler with C++11 support or newer.

Open a terminal in the project folder and build with GCC:

```bash
g++ -std=c++11 -include ctime -include cctype main.cpp -o blackjack
```

Run on Windows:

```powershell
.\blackjack.exe
```

Run on macOS or Linux:

```bash
./blackjack
```

Keep `rules.txt` and `scoreboard.txt` in the folder where you run the program.

## Project Files

- `main.cpp` — game logic.
- `rules.txt` — rules displayed to the player.
- `scoreboard.txt` — saved high score.
- `docs/` — algorithms, diagrams, and gameplay screenshots.

## Gameplay



## Project Scope

This is a console game using simulated money. It uses simplified Blackjack rules, including no card splitting.

**Course:** Computer Science I  
**Date:** June 14, 2023
