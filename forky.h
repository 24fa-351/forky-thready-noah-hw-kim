#ifndef FORKY_H
#define FORKY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdbool.h>

#define MIN_VALUE 1
#define MAX_VALUE 8

void pattern_one_child_process(int processNum);
void pattern_one_fork(int numOfProcesses);
void pattern_two_fork(int numOfProcesses);
void pattern_two_child_process(int processNum, int numOfProcesses);
// void pattern_three_fork(int numOfProcesses);
// void pattern_three_child_process(int numOfProcesses);

// static int curProcessNum;

#endif