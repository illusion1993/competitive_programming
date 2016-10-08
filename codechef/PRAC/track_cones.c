#include<stdio.h>
#include<math.h>
int main(){
    int t, r, R, c, co[500][500], i;
    float max, tmp;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &r, &R, &c);
        i=c;
        while(i--){
            scanf("%d %d", &co[c-i][0], &co[c-i][1]);
        }
        max=sqrt((co[0][0]*co[0][0])+(co[0][1]*co[0][1]))-r;
        for(i=0; i<c; i++){
            tmp=sqrt((co[i][0]*co[i][0])+(co[i][1]*co[i][1]));
            tmp=((tmp-r)>(R-tmp))?tmp-r:R-tmp;
            if(tmp<max) max=tmp;
        }
        printf("%.3f", max);
    }
    return 0;
}
