#include<bits/stdc++.h>
#define FUN(a,b,c) c t;t = a;a = b;b = t;
using namespace std;
int f(int &x, int c){
    c = c - 1;
    if(c == 0) return 1;
    x = x + 1;
    return f(x, c) * x;
}
int main(){
    char s1[7] = "1234", *p;
    p = s1 + 2;
    *p = '\0';
    printf("%s", s1);
    return 0;
}
