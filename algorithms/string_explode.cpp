#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iterator>

using namespace std;
int main(){
    string s = "What is the right way to split a string into a vector of strings";
    stringstream ss(s);
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;
    vector<string> vstrings(begin, end);
    copy(vstrings.begin(), vstrings.end(), ostream_iterator<string>(cout, "\n"));

    return 0;
}
