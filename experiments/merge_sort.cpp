#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &left, vector<int> &right, vector<int> &a){

    cout << "Merging ";
    for(int i = 0; i < left.size(); i++) cout << left[i] << " ";
    cout << ", and ";
    for(int i = 0; i < right.size(); i++) cout << right[i] << " ";
    cout << " At ";
    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;

    int x, y, z;
    x = 0;
    y = 0;
    z = 0;

    while(x < left.size() && y < right.size()){

        if(left[x] <= right[y]){
            cout << "putting a[" << z << " = " << left[x] << endl;
            a[z] = left[x];
            x++;
        }

        else{
            cout << "putting a[" << z << " = " << right[y] << endl;
            a[z] = right[y];
            y++;
        }

        z++;

    }

    while(x < left.size()){
        cout << "putting a[" << z << " = " << left[x] << endl;
        a[z] = left[x];
        x++;
        z++;
    }

    while(y < right.size()){
        cout << "putting a[" << z << " = " << right[y] << endl;
        a[z] = right[y];
        y++;
        z++;
    }

}

void mergeSort(vector<int> &a){

    cout << "mergeSort called for ";
    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;

    int n = a.size();

    if(n < 2) return;

    vector<int> left, right;
    for(int i = 0; i < n / 2; i++) left.push_back(a[i]);
    for(int i = n / 2; i < n; i++) right.push_back(a[i]);

    cout << "Left is : ";
    for(int i = 0; i < left.size(); i++) cout << left[i] << " ";
    cout << ", Right is : ";
    for(int i = 0; i < right.size(); i++) cout << right[i] << " ";
    cout << endl << endl;

    mergeSort(left);
    mergeSort(right);

    merge(left, right, a);

}

int main(){

    vector<int> a;
    a.push_back(5);
    a.push_back(4);
    a.push_back(3);
    a.push_back(2);
    a.push_back(1);

    mergeSort(a);

    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";

    return 0;

}
