#include<iostream>
#include<string>
#include <sstream>
#include<vector>

using namespace std;

std::string::size_type sz;

vector<string> data;
string s;
int holding1=0, holding2=0, holding3=0, holding4=0, holding5=0, total=0;

int stoi (const string& str) {
    stringstream ss(str);
    int n;
    ss >> n;
    return n;
}

string getName(int n){
    if(n==1) return data[0];
    else if(n==2) return data[23];
    else if(n==3) return data[46];
    else if(n==4) return data[69];
    else if(n==5) return data[92];
}

int getPos(string s){
    if(s == data[0]) return 1;
    if(s == data[23]) return 2;
    if(s == data[46]) return 3;
    if(s == data[69]) return 4;
    if(s == data[92]) return 5;
}

int getValue(int day, int pos){
    int index;

    if(pos==1) index=0;
    else if(pos==2) index=23;
    else if(pos==3) index=46;
    else if(pos==4) index=69;
    else if(pos==5) index=92;

    if(day<6) index+=day;
    else if(day > 7 && day < 13) index+=(day-2);
    else if(day > 14 && day < 20) index+=(day-4);
    else if(day > 21 && day < 27) index+=(day-6);
    else if(day > 28) index+=(day-8);

    return stoi(data[index]);
}

int main(){

    while(s != "-1"){
        cin>>s;
        data.push_back(s);
    }

    int marker = 115;
    //cout<<data[marker];

    while(data[marker] != "-1"){

        int day = stoi(data[marker]);
        int firm = getPos(data[marker+2]);
        int count = stoi(data[marker+3]);

        if(data[marker+1] == "B"){
            total -= count*getValue(day, firm);
            if(firm == 1) holding1+=count;
            else if(firm == 2) holding2+=count;
            else if(firm == 3) holding3+=count;
            else if(firm == 4) holding4+=count;
            else if(firm == 5) holding5+=count;
        }

        else if(data[marker+1] == "S"){
            total += count*getValue(day, firm);
            if(firm == 1) holding1-=count;
            else if(firm == 2) holding2-=count;
            else if(firm == 3) holding3-=count;
            else if(firm == 4) holding4-=count;
            else if(firm == 5) holding5-=count;
        }

        marker+=4;
    }

    if(holding1 != 0) cout<<getName(1)<<" "<<holding1<<endl;
    if(holding2 != 0) cout<<getName(2)<<" "<<holding2<<endl;
    if(holding3 != 0) cout<<getName(3)<<" "<<holding3<<endl;
    if(holding4 != 0) cout<<getName(4)<<" "<<holding4<<endl;
    if(holding5 != 0) cout<<getName(5)<<" "<<holding5<<endl;

    if(total > 0) cout<<"Profit = "<<total;
    else if(total < 0) cout<<"Loss = "<<-1*total;


    return 0;
}
