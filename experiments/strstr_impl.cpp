#include <iostream>
#include <vector>

using namespace std;

int main(){

    string haystack, needle;

    cin >> haystack >> needle;

    if(haystack.length() == 0 || needle.length() == 0) cout << "-1";

    int pos, ptr = 0, ptr1 = 0, ptr2 = 0;
    bool found;

    while(!found && ptr <= (haystack.length() - needle.length())){

        ptr1 = ptr;
        ptr2 = 0;

        if(haystack[ptr1] == needle[ptr2]){
            pos = ptr1;
        }

        while(haystack[ptr1] == needle[ptr2] && ptr2 <= needle.length() - 1){
            ptr1++;
            ptr2++;
        }

        if(ptr2 == needle.length()) found = true;

        ptr++;
    }

    if(found) cout << "pos found: " << pos;
    else cout << "-1";

    return 0;

}
