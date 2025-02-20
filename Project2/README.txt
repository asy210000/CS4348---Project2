READ ME: CS-4348 Project 2 - Simple Hardware Simulator with Round Robin Scheduling

QUICK START:
1. Adjust config settings in main.c as described in the CONFIG section.
2. Run make to compile all .c files.
3. Execute with ./sim.exe.

DESCRIPTION:
In this project, we extend the capabilities of a simple hardware simulator developed in Project 1 by incorporating multiple processes and context switching. 
This simulator now supports a Round Robin scheduling algorithm, allowing multiple programs to run simultaneously in a time-shared manner. 
The primary focus is to simulate a basic operating system's process scheduling and context switching on a simulated hardware platform.

FILES:
1. disk.c - Handles the translation of instructions from a text file into opcode and argument pairs.
2. memory.c - provides a memory array of size 1024x2 to store and retrieve instructions and data.
3. cpu.c - Simulates the execution of instructions stored in memory; fetches, decodes, and executes the instructions.
4. scheduler.c - implements the Round Robin scheduling; Manages multiple processes, handles context switching, and maintains a ready queue for process execution.
5. main.c - The main driver; loads the program into memory and does the execution simulation, which runs cycle by cycle.
6. Header files - provides declarations for functions, constants, and data structures used across different source files. (cpu.h, disk.h, memory.h, scheduler.h)
7. Makefile - Used for compiling all of the source files together.

CONFIG:
1. **File Paths**: On line 10 in main.c file, make sure the file name is set to correct path for "program_list.txt".
This file contains the list of programs and their respective memory addresses. For example, char fname[] = "program_list.txt";
2. **Instruction Set Files**: Verify that all instruction set files referenced in "program_list.txt" ("loop50.txt", "loop100.txt", "loop200.txt") are located in the same directory.
3. **Memory Addresses**: The "program_list.txt" file lists each program with an integer specifying its load address in memory. Make sure they're all in the same directory as your executable.
    For example, 
        "19 loop50.txt" will load "loop50.txt" starting at memory address 19.
        "80 loop100.txt" will load "loop100.txt" starting at memory address 80.
        "150 loop200.txt" will load "loop200.txt" starting at memory address 150.

HOW TO RUN:
1. Use the Makefile I've created to compile all the source files (disk.c, memory.c, cpu.c, scheduler.c, main.c) and run it by typing "make".
2. It should create an executable named "sim.exe". Run it by typing "./sim"
or
3. Manually compile with gcc by entering this command - `gcc main.c disk.c memory.c cpu.c scheduler.c -o sim`
4. Then, run it by typing `./sim`
