#include<bits/stdc++.h>
using namespace std;

int main() {

    int t, hotel_id, occurence;
    string text, word;
    map<string, bool> dict;     // word: true
    map<int, int> occurences;   // hotel_id: occurences
    char tmp;

    getline(cin, text);
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ') {
            dict[word] = true;
            //cout << "Word found: " << word << endl;
            word = "";
        }
        else if ((text[i] > 96 && text[i] < 123) || (text[i] > 64 && text[i] < 91)) {
            word += text[i];
        }
    }
    //cout << "Word found: " << word << endl;
    dict[word] = true;
    word = "";
    text = "";

    cin >> t;
    //cout << "T is " << t << endl;
    while(t--) {
        //cout << "testcase " << t << endl;
        occurence = 0;
        cin >> hotel_id >> tmp;
        word += tmp;
        getline(cin, text);
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') {
                if (dict.count(word)) {
                    occurence++;
                    //cout << "Word " << word << " in review of hotel " << hotel_id << endl;
                }
                word = "";
            }
            else if ((text[i] > 96 && text[i] < 123) || (text[i] > 64 && text[i] < 91)) {
                word += text[i];
            }
        }
        if (dict.count(word)) {
            occurence++;
            //cout << "Word " << word << " in review of hotel " << hotel_id << endl;
        }
        if (occurences.count(hotel_id)) occurences[hotel_id] += occurence;
        else occurences[hotel_id] = occurence;
    }

    cout << occurences[1] << endl << occurences[2];

    return 0;
}
