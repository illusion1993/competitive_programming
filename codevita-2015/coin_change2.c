#include"stdio.h"
#include<string.h>

int sum = 1000;
int coins[4] = {1, 5, 7, 10};
int num = 4;

int findDPMinCoins(int *value, int num, int sum)
{
    int mins[sum+1];
    int i,j;

   for(i=1;i<=sum;i++)
       mins[i] = 100;

    mins[0] = 0;
    for(i=1;i<=sum;i++)
    {
        for(j=0;j<num;j++)
        {
            if(value[j]<=i && ((mins[i-value[j]]+1) < mins[i]))
            {
                mins[i] = mins[i-value[j]] + 1;
            }
        }
    }
    return mins[sum];
}

int main(){
    printf("%d", findDPMinCoins(coins, num, sum));

    return 0;
}
