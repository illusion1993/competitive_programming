#include <bits/stdc++.h>

using namespace std;

class LogicGate {

};

class AndGate: public LogicGate {
};

class OrGate: public LogicGate {

};

int main() {

    OrGate og;
    AndGate ag;

    vector<LogicGate*> inputs_for_and;
    inputs_for_and.push_back(&og);
    //ag.set_inputs(inputs_for_and);


    return 0;
}
