<h1 align="center">push_swap</h1>
<h3 align="center">42Paris School Project</h3>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" alt="Language">
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

## About the Project

`push_swap` is an algorithmic challenge that sorts integers using two stacks (A and B) with a limited set of operations. Developed as part of the 42Paris curriculum, this project demonstrates efficient algorithm design, stack manipulation, and optimization techniques to achieve minimal move counts. The bonus `checker` program validates sorting instructions.

## Features

- **Stack Operations**: Supports 11 operations including `sa`, `pb`, `ra`, `rrr`, etc.
- **Optimized Sorting**:
  - 3 numbers sorted in ≤ 2 moves
  - 5 numbers sorted in ≤ 12 moves
  - 100 random numbers sorted in < 700 moves (benchmark)
  - 500 random numbers sorted in < 5500 moves (benchmark)
- **Error Handling**: Detects invalid arguments, duplicates, and non-integer values.
- **Bonus Checker**: Validates if instructions correctly sort the stack.
- **Efficient Algorithms**: Combines insertion sort for small stacks with a partition-based approach for large datasets.

## Technical Details

- **Language**: C
- **Libraries**: Custom `libft` for utilities (e.g., `ft_printf`, `ft_split`)
- **Data Structures**: Doubly linked lists for stack management
- **Complexity**: O(n log n) average case for large stacks

## Getting Started

### Prerequisites

- C compiler (e.g., `gcc`)
- GNU Make

### Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/<your-username>/push_swap.git
   cd push_swap
   ```

2. Compile the project:
   ```sh
   make
   ```

### Usage

**Sort numbers with push_swap**:
```sh
./push_swap 3 1 4 2 5   # Output: sa ra pb pa (example)
```

**Validate results with checker**:
```sh
./push_swap 3 1 4 | ./checker 3 1 4   # Output: OK/KO
```

**Performance test**:
```sh
ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
./push_swap $ARG | wc -l              # Show move count
./push_swap $ARG | ./checker $ARG     # Verify sorting
```

## Project Structure

```
.
├── includes/           # Header files
│   ├── pushswap.h      # Core definitions
│   └── libft.h         # Custom library utilities
├── libft/              # 42's libft implementation
├── srcs/
│   ├── big_sort.c      # Algorithm for 100+ numbers
│   ├── short_sort.c    # Algorithm for 3-5 numbers
│   ├── checker.c       # Bonus instruction validator
│   ├── operations.c    # Stack operations (push/swap/rotate)
│   └── parsing.c       # Argument validation
└── Makefile            # Build script
```

## Key Components

- **Parsing**: Validates input and converts to linked list stack.
- **Indexing**: Assigns normalized indexes to numbers for efficient comparisons.
- **Cost Calculation**: Determines optimal moves for each element.
- **Move Optimization**: Combines rotations (e.g., `rr`/`rrr`) to reduce total operations.

## Acknowledgements

Developed as part of the 42Paris curriculum. Special thanks to the 42 community for algorithm discussions and optimization techniques.

---

<p align="left">
  <a href="https://www.linkedin.com/in/your-profile" target="blank">
    <img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="Your Name" height="30" width="40" />
  </a>
</p>
