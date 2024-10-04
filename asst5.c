#include "forky_thready.h"

/*
Assignment 6: forky-thready
*/


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
        patten_two_fork(0, numOfSubProcesses - 1);
    } else {
        printf("invalid");
    }

    return 0;
}