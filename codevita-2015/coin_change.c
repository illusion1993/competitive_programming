#include"stdio.h"
#include<string.h>

int min[65] = {100};
int coin[4] = {1, 5, 7, 10};

void
findMin (int sum)
{
    int i = 0; int j=0;
    min [0] = 0;

    for (i = 1; i <= sum; i++) {
        /* Find solution for Sum = 0..Sum = Sum -1, Sum, i represents sum
         * at each stage */
        for (j=0; j<= 3; j++) {
            /* Go over each coin that is lesser than the sum at this stage
             * i.e. sum = i */
            if (coin[j] <= i) {
                if ((1 + min[(i - coin[j])]) <= min[i]) {
                    /* E.g. if coin has value 2, then for sum i = 5, we are
                     * looking at min[3] */
                    min[i] = 1 + min[(i-coin[j])];
                    printf("\nsetting min[%d] %d",i, min[i]);
                }
            }
        }
    }
}
void
initializeMin()
{
    int i =0;
    for (i=0; i< 66; i++) {
        min[i] = 100;
    }
}
void
dumpMin()
{
    int i =0;
    for (i=0; i< 66; i++) {
        printf("\n Min[%d]: %d", i, min[i]);
    }
}
int main()
{
    initializeMin();
    findMin(23);
    dumpMin();
}
