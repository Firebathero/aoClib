# aoClib

![AoC Logo](https://adventofcode.com/favicon.png)



## Quick Start

Build the project:
```bash
make
```

Run a solution:
```bash
./build/aoc_solve <day>
```
Example: `./build/aoc_solve 4` runs Day 4's solution

## Debug Build & Valgrind Analysis

1. Install tools (first-time setup):
   ```bash
   ./util/setup_tools.sh
   ```

2. Build with debug symbols:
   ```bash
   make debug
   ```

3. Run Valgrind analysis:
   ```bash
   make valgrind DAY=<day_number>
   ```

4. Analyze with KCachegrind:
   ```bash
   kcachegrind valgrind_output/callgrind_day<day_number>.out
   ```

## Project Structure

```
aoclib/
├── include/           # Header files
│   └── aocutil/       # Utility headers
├── src/
│   ├── main.c         # Main entry point
│   └── days/          # Individual day solutions
├── input/             # Input files (e.g., day4.txt)
├── util/              # Utility scripts
├── Makefile           # Build configuration
└── CMakeLists.txt     # CMake configuration
```