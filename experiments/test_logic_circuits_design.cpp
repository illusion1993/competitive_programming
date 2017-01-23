#include <bits/stdc++.h>

using namespace std;

class Circuit {

};

class LogicGate {
    public:
        virtual bool get_output() = 0;

};

class Terminal : public LogicGate {
    public:
        Terminal() {}
        Terminal(bool value) : value(value) {}

        void set_value(bool new_value) {
            value = new_value;
        }

        virtual bool get_output() {
            return value;
        }

    private:
        bool value;
};

class AndGate: public LogicGate {
    public:
        AndGate() {}
        AndGate(vector<LogicGate *> inputs_addresses) : inputs(inputs_addresses) {}
        AndGate(LogicGate * input_a, LogicGate * input_b) {
            inputs.push_back(input_a);
            inputs.push_back(input_b);
        }

        void set_inputs(vector<LogicGate *> inputs_addresses) {
            inputs = inputs_addresses;
        }

        virtual bool get_output() {
            return inputs[0] -> get_output() && inputs[1] -> get_output();
        }

    private:
        vector<LogicGate *> inputs;
};

class OrGate: public LogicGate {
    public:
        OrGate() {}
        OrGate(vector<LogicGate *> inputs_addresses) : inputs(inputs_addresses) {}
        OrGate(LogicGate * input_a, LogicGate * input_b) {
            inputs.push_back(input_a);
            inputs.push_back(input_b);
        }

        void set_inputs(vector<LogicGate *> inputs_addresses) {
            inputs = inputs_addresses;
        }

        virtual bool get_output() {
            return inputs[0] -> get_output() || inputs[1] -> get_output();
        }

    private:
        vector<LogicGate *> inputs;
};

class NotGate: public LogicGate {
    public:
        NotGate() {}
        NotGate(vector<LogicGate *> inputs_addresses) : inputs(inputs_addresses) {}
        NotGate(LogicGate * input_a) {
            inputs.push_back(input_a);
        }

        void set_inputs(vector<LogicGate *> inputs_addresses) {
            inputs = inputs_addresses;
        }

        virtual bool get_output() {
            return !inputs[0] -> get_output();
        }

    private:
        vector<LogicGate *> inputs;
};

int main() {
    Terminal A, B, C;
    NotGate ng(&A);
    AndGate ag(&ng, &B);
    AndGate ag1(&ag, &C);

    bool ip;
    cout << "Enter input values of A, B, C: ";
    cin >> ip;
    A.set_value(ip);
    cin >> ip;
    B.set_value(ip);
    cin >> ip;
    C.set_value(ip);

    cout << ag1.get_output();

    return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;

class Terminal {
    public:
        Terminal(bool value) : value(value) {}

        void set_value(bool new_value) {
            value = new_value;
        }

        bool get_output() {
            return value;
        }

    private:
        bool value;
};

class LogicGate {
    public:
        virtual bool process_inputs() = 0;

    protected:
        bool output;

};

class AndGate: public LogicGate {
    public:
        AndGate(vector<LogicGate *> inputs){
            cout << "created and gate with " << inputs.size() << " Inputs";
        }

        virtual bool process_inputs() {
            //*output = *inputs[0] && *inputs[1];
            //return *output;
            return false;
        }
};

class OrGate: public LogicGate {
    public:
        OrGate(bool * output_pointer) : LogicGate(output_pointer){
            number_of_inputs = 2;
        }

        virtual bool process_inputs() {
            *output = *inputs[0] || *inputs[1];
            return *output;
        }
};

class NotGate: public LogicGate {
    public:
        NotGate(bool * output_pointer) : LogicGate(output_pointer){
            number_of_inputs = 1;
        }

        virtual bool process_inputs() {
            *output = !*inputs[0];
            return *output;
        }
};

int main() {

    OrGate og;
    NotGate ng;


    return 0;
}
*/

/*
#include <bits/stdc++.h>

using namespace std;

class Terminal {
    public:
        Terminal(bool value) : value(value) {}

        void set_value(bool new_value) {
            value = new_value;
        }

        bool get_output() {
            return value;
        }

    private:
        bool value;
};

class LogicGate {
    public:
        LogicGate(bool * output_pointer) {
            output = output_pointer;
        }

        int get_number_of_inputs() {
            return number_of_inputs;
        }

        void push_input_pointer(bool* input_pointer) {
            if (inputs.size() < number_of_inputs) {
                inputs.push_back(input_pointer);
            }
        }

        virtual bool process_inputs() = 0;

    protected:
        bool *output;
        vector<bool*> inputs;
        int number_of_inputs;

};

class AndGate: public LogicGate {
    public:
        AndGate(vector<LogicGate *> inputs) : inputs(inputs) {}

        virtual bool process_inputs() {
            *output = *inputs[0] && *inputs[1];
            return *output;
        }

    private:
        vector<LogicGate *> inputs;
};

class OrGate: public LogicGate {
    public:
        OrGate(bool * output_pointer) : LogicGate(output_pointer){
            number_of_inputs = 2;
        }

        virtual bool process_inputs() {
            *output = *inputs[0] || *inputs[1];
            return *output;
        }
};

class NotGate: public LogicGate {
    public:
        NotGate(bool * output_pointer) : LogicGate(output_pointer){
            number_of_inputs = 1;
        }

        virtual bool process_inputs() {
            *output = !*inputs[0];
            return *output;
        }
};

int main() {

    bool inputs[] = {1, 1, 0, 0};

    OrGate og( &inputs[3] );
    AndGate ag();

    ag.push_input_pointer( &inputs[0] );
    ag.push_input_pointer( &inputs[1] );

    og.push_input_pointer( &inputs[1] );
    og.push_input_pointer( &inputs[2] );

    ag.process_inputs();
    og.process_inputs();

    cout << "Final values: " << endl;
    for (int i = 0; i < sizeof(inputs); i++) {
        cout << inputs[i] << " ";
    }

    vector<LogicGate *> inputs_for_and;
    inputs_for_and.push_back(&og);
    ag.set_inputs(inputs_for_and);


    return 0;
}
*/
