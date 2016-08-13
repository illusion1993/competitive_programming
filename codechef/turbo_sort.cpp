#include<stdio.h>
int main(){
    int t, n, arr[1000000], i=0, j;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(i==0) arr[0]=n;
        else{
            j=0;
            while(arr[j]<n){
                j++;
            }
            for(int k=i; k>j; k--){
                arr[k]=arr[k-1];
            }
            arr[j]=n;
        }
        i++;
    }
    for(int j=0; j<i; j++){
        printf("%d\n", arr[j]);
    }
    return 0;
}
