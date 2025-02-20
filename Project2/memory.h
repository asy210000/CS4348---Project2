#ifndef MEMORY_H
#define MEMORY_H

extern int memory[1024][2];

int* mem_read(int addr);
void mem_write(int addr, int* data);
void initialize_memory();

#endif // MEMORY_H