#ifndef FORKY_H
#define FORKY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void child_process(int processNum);
void patten_one_fork(int numOfSubProcesses);
void patten_two_fork(int processNum, int numOfSubProcesses);

#endif