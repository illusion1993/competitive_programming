#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int GetJumpCount(int input1,int input2,int input3_size, int* input3)
{
    int jumps = 0, h;

    for (int i = 0; i < input3_size; i++) {
    	h = 0;
    	while(h < input3[i]) {
    		if (h != 0) h -= input2;
    		h += input1;
    		jumps++;
    	}
    }
    return jumps;
}

int main() {
    int output = 0;
    int ip1;
    scanf("%d", &ip1);
    int ip2;
    scanf("%d", &ip2);
    int ip3_size = 0;
    int ip3_i;
    scanf("%d\n", &ip3_size);
    int ip3[ip3_size];
    for(ip3_i = 0; ip3_i < ip3_size; ip3_i++) {
        int ip3_item;
        scanf("%d", &ip3_item);
        
        ip3[ip3_i] = ip3_item;
    }
    output = GetJumpCount(ip1,ip2,ip3_size,ip3);
    printf("%d\n", output);
    return 0;
}