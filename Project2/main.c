#include <stdio.h>
#include "disk.h"
#include "memory.h"
#include "cpu.h"
#include "scheduler.h"
#include <pthread.h>

int main() {
    initialize_memory();
    char fname[] = "program_list.txt"; // file path
    int running = 1;
    int cycle_count = 0;

    // Initialize the system and load the programs
    load_programs(fname);

    if (readyQueue != NULL) {
        PCB *firstProcess = readyQueue->data;

        // Set the CPU's state for the first process
        Base = firstProcess->Base;
        PC = firstProcess->PC;
        //printf("Starting first process with Base: %d, PC: %d\n", Base, PC);
    }

    // Main scheduling loop
    while (running) {
        printf("Cycle count: %d\n", cycle_count);
        int clock_ret = clock_cycle(); // Simulate a clock cycle
        running = schedule(cycle_count, clock_ret); // Determine if we should continue running
        cycle_count++;

        // Check if there are no more processes to run
        if (!running) {
            printf("All processes have completed or the ready queue is empty.\n");
            break; // Exit the scheduling loop
        }
    }
    // After the scheduling is done
    for (int i = 0; i < 20; i++) { // Print the first 20 memory locations
        int* data = mem_read(i);
        if(data != NULL) {
            printf("Memory[%d] - Opcode: %d Argument: %d\n", i, data[0], data[1]);
        } else {
            printf("Memory[%d] - Empty\n", i);
        }
    }
    return 0;
}
