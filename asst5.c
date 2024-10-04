#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

/*
Assignment 6: forky-thready
*/

void child_process(int processNum) {
    printf("Process %d(%d) beginning \n", processNum, getpid());

    int sleep_time = rand() % (8 + 1 - 1) + 1;
    sleep(sleep_time);

    printf("Process %d(%d) exiting \n", processNum, getpid());
}

void patten_one_fork(int numOfSubProcesses) {
    int pids[numOfSubProcesses];
    
    for (int idx = 1; idx < numOfSubProcesses; idx++) {
        int pId = fork();

        if (pId == 0) {
            child_process(idx);
            exit(0);
        } else if (pId > 0) {
            printf("Main Process (%d) creating Process %d(%d) \n", getpid(), idx, pId);
        } else {
            perror("Fork failed");
            exit(1);
        }
    }

    for (int idx = 0; idx <= numOfSubProcesses; idx++) {
        waitpid(pids[idx], NULL, 0);
    }

    printf("Main Process (%d) exiting \n", getpid());
}

void patten_two_fork(int processNum, int numOfSubProcesses) {
    printf("Process %d (%d) beginning \n", processNum, getpid());
    
    int sleep_time = rand() % (8 + 1 - 1) + 1;
    sleep(1);

    if (processNum < numOfSubProcesses) {
        int pId = fork();
        
        if (pId == 0) {
            patten_two_fork(processNum + 1, numOfSubProcesses);
            exit(0);
        } else if (pId > 0) {
            printf("Process %d (%d) creating Process %d (%d) \n", processNum, getpid(), processNum + 1, pId);
            waitpid(pId, NULL, 0);
        } else {
            perror("Fork failed");
            exit(1);
        }
    }

    printf("Process %d (%d) exiting \n", processNum, getpid());
}

int main(int argc, char *argv[]) {
    int numOfSubProcesses;
    int patternNum;

    // not enough arguments passed
    if (argc < 3 
        || !argv[1]
        || 0 == sscanf(argv[1], "%d", &numOfSubProcesses) 
        || (numOfSubProcesses < 1 || numOfSubProcesses > 256) 
        || 0 == sscanf(argv[2], "%d", &patternNum) 
        || (patternNum < 1 || patternNum > 3)) {
        printf("Usage: %s <positive integer - between 1 and 256> <positive integer - pattern number between 1 and 3>\n", argv[0]);
        return 1;
    }

    if (patternNum == 1) {
        patten_one_fork(numOfSubProcesses);
    } else if (patternNum == 2) {
        patten_two_fork(1, numOfSubProcesses);
    } else {
        printf("invalid");
    }

    return 0;
}