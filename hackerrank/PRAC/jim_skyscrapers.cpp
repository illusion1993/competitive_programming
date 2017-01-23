#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> stack, fcount;
int paths = 0;

int ncr(int n){
    if(n<2) return 0;
    else return n*(n-1)/2;
}

void push(int n){
    stack.insert(stack.begin(), n);
    fcount.insert(fcount.begin(), 1);
}

void pop(){
    paths += ncr(fcount[0]);
    stack.erase(stack.begin());
    fcount.erase(fcount.begin());
}

void increment(){
    fcount[0]++;
}

int top(){
    if(stack.size()) return stack[0];
    else return 0;
}

bool isempty(){
    if(stack.size()==0) return true;
    else return false;
}



int main() {
    int n, h;

    cin>>n;

    cin>>h;
    n--;
    push(h);
    while(n--){
        cin>>h;
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

    if(!isempty())
        pop();

    cout<<2*paths;

    return 0;
}
