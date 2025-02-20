#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include <pthread.h>

// Defining the memory as a 2D array
int memory[1024][2];

void initialize_memory() {
    for (int i = 0; i < 1024; i++) {
        memory[i][0] = 0; // Initialize opcode to 0
        memory[i][1] = 0; // Initialize operand to 0
    }
}

// Function to read from the memory
int* mem_read(int addr) {
    if (addr < 0 || addr >= 1024) {
        fprintf(stderr, "Error: Memory address out of bounds.\n");
        exit(EXIT_FAILURE);
    }
    //printf("Memory read from address %d: [%d, %d]\n", addr, memory[addr][0], memory[addr][1]);
    return memory[addr];
}

void mem_write(int addr, int* data) {
    //printf("Writing to memory address %d: Opcode: %d, Operand: %d\n", addr, data[0], data[1]);

    if (addr < 0 || addr >= 1024) {
        fprintf(stderr, "Error: Memory address out of bounds.\n");
        exit(EXIT_FAILURE);
    }
    memory[addr][0] = data[0]; // Write the opcode
    memory[addr][1] = data[1]; // Write the operand
    
    //printf("Memory write to address %d: [Opcode: %d, Operand: %d]\n", addr, data[0], data[1]);
}