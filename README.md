# Page Replacement Algorithms

This repository contains implementations of two page replacement algorithms: the Reference Bit Algorithm and the Clock Algorithm. These algorithms are commonly used in operating systems to manage memory pages.

## Files

- `main.cpp`: Contains the main function that runs both algorithms with a sample reference string.
- `algorithm/reference_bit_algorithm.hpp`: Header file for the Reference Bit Algorithm.
- `algorithm/reference_bit_algorithm.cpp`: Implementation of the Reference Bit Algorithm.
- `algorithm/clock_algorithm.hpp`: Header file for the Clock Algorithm.
- `algorithm/clock_algorithm.cpp`: Implementation of the Clock Algorithm.

## Algorithms

### Reference Bit Algorithm
The Reference Bit Algorithm is a simple page replacement algorithm that uses a reference bit to keep track of whether a page has been accessed recently. Pages with a reference bit of 0 are considered for replacement first.

### Clock Algorithm
The Clock Algorithm, also known as the Second Chance Algorithm, is a more efficient version of the FIFO algorithm. It uses a circular buffer (or "clock") to keep track of pages and their reference bits. When a page needs to be replaced, the algorithm gives a second chance to pages with a reference bit of 1 before replacing pages with a reference bit of 0.

## How to Build

To build the project, use the following command:
```sh
g++ -o page_replacement main.cpp algorithm/reference_bit_algorithm.cpp algorithm/clock_algorithm.cpp
```
## How to Run

After building the project, run the executable with the following command:
```sh
./page_replacement
```

## Output

The program will output the sequence of page references and display the state of memory pages after each reference for both algorithms. It will also show the total number of page faults for each algorithm.

### Example Output
```sh
[Reference Bit Algorithm]
> 1
Pages: | 1 (10000000) | 
> 2
Pages: | 1 (01000000) | 2 (10000000) | 
> 3
Pages: | 1 (00100000) | 2 (01000000) | 3 (10000000) | 
...
Reference Bit Algorithm Page Faults: 15

----------------------------------------

[Clock Algorithm]
> 1
Pages: | 1 (true) <- | 
> 2
Pages: | 1 (true) <- | 2 (true) | 
> 3
Pages: | 1 (true) <- | 2 (true) | 3 (true) | 
...
Clock Algorithm Page Faults: 12
```
