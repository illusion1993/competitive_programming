#include<stdio.h>
int main(){
    int x;
    float b;
    scanf("%d %f", &x, &b);
    if((x%5==0)&&(b>=x+0.50)) printf("%.2f", b-x-0.50);
    else printf("%.2f", b);
    return 0;
}
