#include<stdio.h>
int main(){
    unsigned int n,k,u,d=0;
    scanf("%d %d", &n, &k);
    while(n--){
        scanf("%d", &u);
        if(u%k==0) d++;
    }
    printf("%d", d);
    return 0;
}
