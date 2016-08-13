#include<iostream>

int bottles[4] = {1, 5, 7, 10};
int num = 4;

int findMinBottles(int *value, int num, int sum)
{
    int mins[sum+1];
    int i,j;

   for(i=1;i<=sum;i++)
       mins[i] = i;

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

    int n, l;

    std::cin>>n;
    while(n--){
        std::cin>>l;
        std::cout<<findMinBottles(bottles, num, l);
        if(n > 0) std::cout<<std::endl;
    }

    return 0;
}
