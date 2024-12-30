# Radix Sort Algorithm

## Overview
This repository contains an implementation of the **Radix Sort algorithm** in C++. Radix Sort is a non-comparative sorting algorithm that works by distributing elements into buckets according to their individual digits. This implementation specifically uses **binary Radix Sort**, which processes numbers bit by bit, starting from the least significant bit (LSB) to the most significant bit (MSB).

Radix Sort is particularly efficient when sorting data with a fixed range, such as integers or bytes. This implementation handles a sequence of unsigned 8-bit integers (values between 0 and 255).

## Theory of Radix Sort
Radix Sort works by repeatedly grouping numbers based on the values of their individual digits. In binary Radix Sort, each number is sorted based on its binary representation, one bit at a time. The sorting is stable, meaning that numbers with the same value remain in their original relative order.

### Steps:
1. Start with the least significant bit (LSB).
2. Use a **Counting Sort** algorithm to sort the numbers based on the current bit.
3. Move to the next more significant bit and repeat the process.
4. Continue until all bits have been processed.

### Complexity:
- **Time Complexity**: O(n \* k), where:
  - *n* is the number of elements.
  - *k* is the number of bits (8 for unsigned 8-bit integers).
- **Space Complexity**: O(n + b), where:
  - *n* is the number of elements.
  - *b* is the range of the counting sort buckets (in this case, 2 for binary).

## File Descriptions
### Input File (`input.txt`):
The input file contains a sequence of unsigned integers (bytes) separated by spaces. For example:

```
233 150 54 149 26 225 148 116 254 217 239 46 41 94 174 167 207 19 125 171 119 235 62 187 250 21 148 179 194 ...
```

### Output File (`out.txt`):
After sorting, the program writes the sorted sequence to an output file (`out.txt`). For example:

```
1 1 1 1 1 1 2 2 3 3 4 4 4 4 5 5 5 5 5 5 6 7 7 8 8 8 9 9 9 9 10 10 10 11 11 11 11 11 11 12 12 12 12 13 13 13 13 13 13 14 14 1
```

## Usage
### Compilation
To compile the program, use any standard C++ compiler. For example, with `g++`:

```bash
g++ -o radix_sort radix_sort.cpp
```

### Running the Program
The program takes a single command-line argument: the name of the input file containing the numbers to sort.

```bash
./radix_sort input.txt
```

#### Parameters:
- `input.txt`: The file from which the program reads the numbers to be sorted. Ensure the file is in the same directory as the executable.

### Output
After execution, the program will generate an output file named `out.txt` in the same directory. This file contains the sorted numbers.

### Example
Given the input file `input.txt`:

```
233 150 54 149 26 225 148 116 254
```

Running the program:

```bash
./radix_sort input.txt
```

The output file `out.txt` will contain:

```
26 54 116 148 149 150 225 233 254
```

## How It Works
### Functions
1. **`readNumbers`**:
   Reads numbers from the input file into a vector.

2. **`countingSort`**:
   Performs Counting Sort on the numbers based on a specific bit position.

3. **`binaryRadixSort`**:
   Calls Counting Sort iteratively for each bit position (from LSB to MSB).

4. **`print`**:
   Outputs the sorted numbers to the output file (`out.txt`).

### Main Function
1. Reads the input file specified as a command-line argument.
2. Executes the Radix Sort algorithm on the input data.
3. Writes the sorted result to the output file.

## Error Handling
- If the input file cannot be opened, the program exits gracefully with a message.
- Ensure the input file exists and contains valid integers separated by spaces.

## Requirements
- C++11 or later.
- An input file (`input.txt`) with valid unsigned integers.

