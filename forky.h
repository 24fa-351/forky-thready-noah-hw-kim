#ifndef FORKY_H
#define FORKY_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MIN_VALUE 1
#define MAX_VALUE 8

void pattern_one_child_process(int processNum);
void pattern_one_fork(int numOfProcesses);
void pattern_two_fork(int numOfProcesses);
void pattern_two_child_process(int processNum, int numOfProcesses);

#endif