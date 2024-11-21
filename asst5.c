#include "forky.h"

/*
Assignment 6: forky-thready
*/
int main(int argc, char *argv[]) {
    int numOfProcesses;
    int patternNum;

    FILE *file = freopen("results.txt", "a", stdout);
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // not enough arguments passed
    if (argc < 3 
        || !argv[1]
        || 0 == sscanf(argv[1], "%d", &numOfProcesses) 
        || (numOfProcesses < 1 || numOfProcesses > 256) 
        || 0 == sscanf(argv[2], "%d", &patternNum) 
        || (patternNum < 1 || patternNum > 3)) {
        printf("Usage: %s <positive integer - between 1 and 256> <positive integer - pattern number between 1 and 3>\n", argv[0]);
        return 1;
    }

    printf("Pattern %d: creating %d processes \n", patternNum, numOfProcesses);

    if (patternNum == 1) {
        pattern_one_fork(numOfProcesses);
    } else if (patternNum == 2) {
        pattern_two_fork(numOfProcesses);
    } else if (patternNum == 3) {
        // pattern_three_fork(numOfProcesses);
    } else {
        printf("invalid");
    }

    fclose(file);

    return 0;
}