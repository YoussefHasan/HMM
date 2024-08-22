**Heap Memory Management System**

**Overview**
The HMM Heap memory management system is a simple implementation of a dynamic memory allocating simulation in C. It provides functions to allocate, deallocate, and manipulate memory blocks.

**Features**

* Allocates memory blocks of varying sizes.
* Deallocates memory blocks.
* Allows for inserting nodes at the beginning, end, or after a specific node.
* Deletes nodes from the linked list.

**Usage**

1. Compile the project by running `gcc *.c -o hmm.exe`.
2. Run the program using `./hmm.exe` to execute the random allocation and deallocation test.
3. The program will print messages indicating memory allocations and deallocations, as well as any errors that may occur.

**Test Cases**
The provided `stress_test.c` file contains a test function called `random_alloc_free_test`, which performs a series of random memory allocations and deallocations to validate the functionality of the HMM system.

**Future Development Ideas**

* Implement memory compaction and defragmentation algorithms.
* Add support for allocating memory with specific alignment requirements.
* Enhance the test suite to include more comprehensive testing scenarios.
