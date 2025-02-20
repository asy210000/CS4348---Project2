#ifndef DISK_H
#define DISK_H

#include "scheduler.h"

extern int prog_size;

int* translate(char *instruction);
int load_prog(char* fname, int addr);
void load_programs(char fname[]);

#endif // DISK_H
