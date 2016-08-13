#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int stack[300000], fcount[300000], s_top=-1;
long long paths = 0;

void showStack(){
    cout<<endl<<"____________________________"<<endl;
    for(int i=0; i<=s_top; i++){
        cout<<stack[i]<<" ";
    }
    cout<<endl<<endl;
    for(int i=0; i<=s_top; i++){
        cout<<fcount[i]<<" ";
    }
    cout<<endl<<endl<<endl<<endl;
}

long long ncr(long long n){
    if(n<2) return 0;
    else return n*(n-1);
}

void push(int n){
    stack[s_top+1] = n;
    fcount[s_top+1] = 1;
    s_top++;
    //showStack();
}

void pop(){
    paths += ncr(fcount[s_top]);
    s_top--;
    //showStack();
}

void increment(){
    fcount[s_top]++;
    //showStack();
}

int top(){
    if(s_top != -1) return stack[s_top];
    else return 0;
}

bool isempty(){
    if(s_top == -1) return true;
    else return false;
}


int twocount = 0;

int main() {
    int n, h;

    ifstream myfile ("jim_skyscrapers.txt");
    myfile>>n;
    myfile>>h;

    if(h==2) twocount++;

    //n = 10;
    n--;
    push(h);
    while(n--){
        myfile>>h;
        if(h==2) twocount++;

        if(h < top())
            push(h);

        else if(h == top())
            increment();

        else if(h > top()){
            while(!isempty() && h > top())
                pop();

            if(!isempty() && h == top())
                increment();

            else
                push(h);
        }

    }

    cout<<"two count : "<<twocount<<endl;
    cout<<"shud be at least paths "<<ncr(twocount)<<endl;

    showStack();
    while(!isempty())
        pop();

    cout<<paths;

    return 0;
}
