#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    int t;
    long long int index, i;
    char path[100001];
    scanf("%d", &t);
    while(t--){
        index=1;
        scanf("%s", path);
        for(i=0; i<strlen(path); i++){
            if(path[i]=='l') index=((index-1)*2)+1;
            else if(path[i]=='r') index=((index-1)*2)+2;
        }
        for(i=1; i<strlen(path)+1; i++){
            if(strlen(path)%2==1 && i%2==0) index+=pow(2,i-1);
            else if(strlen(path)%2==0 && i%2==1) index+=pow(2,i-1);
        }
        if(strlen(path)%2==1) printf("%d\n", 0+(index*2));
        else if(strlen(path)%2==0) printf("%d\n", -1+(index*2));
    }

}
