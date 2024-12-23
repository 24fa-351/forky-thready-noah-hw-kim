#include "forky.h"

void pattern_one_child_process(int processNum) {
    int sleep_time = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

    printf("Process %d (pid %d) created: will sleep for %d seconds \n",
           processNum, getpid(), sleep_time);

    sleep(sleep_time);

    printf("Process %d (pid %d) exiting \n", processNum, getpid());
}

void pattern_one_fork(int numOfProcesses) {
    for (int idx = 0; idx < numOfProcesses; idx++) {
        int pId = fork();

        if (pId == 0) {
            pattern_one_child_process(idx);
            return;
        } else if (pId > 0) {
            printf("Parent: created child %d (pid %d) \n", idx, pId);
        } else {
            perror("Fork failed");
            exit(1);
        }
    }
    printf("**Pattern 1: All processes created \n");

    wait(NULL);
    printf("Parent (pid %d) exiting \n", getpid());
    printf("**Pattern 1: All children have exited \n");
}

void pattern_two_child_process(int processNum, int numOfProcesses) {
    printf("Child %d (pid %d): starting \n", processNum, getpid());

    int sleep_time = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

    if (processNum >= numOfProcesses) {
        printf(
            "Child %d (pid %d), [no children created] sleeping %d seconds \n",
            processNum, getpid(), sleep_time);
        sleep(sleep_time);
        printf("Child %d (pid %d) exiting.\n", processNum, getpid());
        return;
    }

    int pId = fork();

    if (pId == 0) {
        pattern_two_child_process(processNum + 1, numOfProcesses);
        exit(0);
    } else if (pId > 0) {
        printf(
            "Child %d (pid %d), sleeping %d seconds after creating child %d "
            "(pid %d) \n",
            processNum, getpid(), sleep_time, processNum + 1, pId);
        sleep(sleep_time);
        printf("Child %d (pid %d), waiting for child %d (pid %d) \n",
               processNum, getpid(), processNum + 1, pId);
        waitpid(pId, NULL, 0);
        // wait(NULL);
        printf("Child %d (pid %d) exiting.\n", processNum, getpid());
    } else {
        perror("Fork failed");
        exit(1);
    }
}

void pattern_two_fork(int numOfProcesses) {
    int processNum = 0;
    int pId = fork();

    if (pId == 0) {
        pattern_two_child_process(processNum, numOfProcesses - 1);
        exit(0);
    } else if (pId > 0) {
        printf("Parent: created child %d (pid %d)\n", processNum, pId);
        waitpid(pId, NULL, 0);
        printf("Parent: child %d (pid %d) has exited\n", processNum, pId);
        printf("**Pattern 2: All children have exited\n");
    } else {
        perror("Fork failed");
        exit(1);
    }
}