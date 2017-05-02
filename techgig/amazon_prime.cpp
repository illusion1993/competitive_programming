#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* longestIncreasingSubsequence(char* input1){
    int n;
}

int main() {
    char* output;
    char* ip1;
    ip1 = (char *)malloc(512000 * sizeof(char));
    scanf("\n%[^\n]",ip1);
    output = longestIncreasingSubsequence(ip1);
    printf("%s\n", output);
    return 0;
}