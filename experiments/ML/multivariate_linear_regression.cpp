#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <double> parameters;
vector <double> parameters_new;
vector <double> parameters_old;
vector <vector <double> > inputs;
vector <vector <double> > tests;
vector <double> outputs;
vector <double> difference;
vector <double> predictions;

// Learning rate and max allowed error
double alpha = 0.00001, max_allowed_RMS_error = 10.0, previous_RMS_error;

// Function to compute prediction/output according to current hypothesis, taking the inputs vector as a parameter
double predict(vector<double> features){

    double prediction = 0.0;

    for(int i = 0; i < features.size(); i++){
        prediction += features[i] * parameters[i];
    }

    return prediction;

}

// Function to calculate RMS error in the current hypothesis, based on training data
double RMSerror(){

    double error = 0.0, prediction;

    for(int i = 0; i < inputs.size(); i++){

        prediction = 0.0;
        for(int j = 0; j < inputs[i].size(); j++){
            prediction += inputs[i][j] * parameters[j];
        }

        error += (prediction - outputs[i]) * (prediction - outputs[i]);

    }

    // Finding mean of square errors
    error /= inputs.size();

    // Root of Mean Square errors
    error = sqrt(error);

    return error;

}

// Function to calculate differences between prediction and output for given training sets, this is (h(xi) - yi) for derivatives
void computeDifferences(){

    double prediction;

    for(int i = 0; i < inputs.size(); i++){

        prediction = predict(inputs[i]);
        difference.push_back(prediction - outputs[i]);

    }

}

// Function to do one iteration of linear regression
void regressionIterate(){

    // Prepare differences vector, for derivative purpose
    computeDifferences();
    double derivative;

    for(int i = 0; i < parameters.size(); i++){

        derivative = 0.0;

        for(int j = 0; j < inputs.size(); j++){
            derivative += difference[j] * inputs[j][i];
        }

        derivative /= inputs.size();

        parameters_new[i] = parameters[i] - (alpha * derivative);

    }

    for(int i = 0; i < parameters.size(); i++){
        parameters[i] = parameters_new[i];
        parameters_old[i] = parameters[i];
    }

    //cout << "\nRMS error is : " << RMSerror();
    //if(RMSerror() > 1) regressionIterate();

    // If new RMS error is less than previous, recall regression
    if(previous_RMS_error > RMSerror()){
        previous_RMS_error = RMSerror();
        regressionIterate();
    }
    // Else revert the values of parameters
    else{
        for(int i = 0; i < parameters.size(); i++){
            parameters[i] = parameters_old[i];
        }
    }

}

// Function to display all data
void showData(){

    // Showing parameters (thetas)
    cout << "\n\nThe " << parameters.size() << " parameters formed for this hypothesis are : \n" ;

    for(int i = 0; i < parameters.size(); i++)
        cout << parameters[i] << " ";

    // Showing all entered training inputs
    cout << "\n\nThe " << inputs.size() << " input examples given are : \n" ;

    for(int i = 0; i < inputs.size(); i++){
        for(int j = 0; j < inputs[i].size(); j++){
            cout << inputs[i][j] << " ";
        }
        cout << "\n";
    }

    // Showing all training outputs
    cout << "\n\nThe " << outputs.size() << " outputs for training data are : \n" ;

    for(int i = 0; i < outputs.size(); i++)
        cout << outputs[i] << "\n";

    // Showing all test cases
    cout << "\n\nThe " << tests.size() << " test cases given are : \n" ;

    for(int i = 0; i < tests.size(); i++){
        for(int j = 0; j < tests[i].size(); j++){
            cout << tests[i][j] << " ";
        }
        cout << "\n";
    }

    // Showing all test case predicted outputs
    cout << "\n\nThe " << predictions.size() << " predicted outputs for test data are : \n" ;

    for(int i = 0; i < predictions.size(); i++)
        cout << predictions[i] << "\n";

}

int main(){

    int f, n, t;
    cin >> f >> n;

    // Initialize parameters (theta), taking f + 1 parameters because first one is constant (theta0)
    for(int i = 0; i <= f; i++){
        parameters.push_back(0.0);
        parameters_new.push_back(0.0);
        parameters_old.push_back(0.0);
    }

    // Taking n lines of training data
    for(int i = 0; i < n; i++){

        vector<double> input;
        double val;

        for(int j = 0; j <= f; j++){
            // Initializing first feature as 1.0, which would multiply with theta0 and form a constant
            if( j == 0 ) input.push_back(1.0);

            // Inputting the input values for this training example
            else{
                cin >> val;
                input.push_back(val);
            }
        }

        // Pushing the whole set of inputs for this training example in the inputs matrix
        inputs.push_back(input);
        // Inputting the output/result of this training example and pushing in outputs vector
        cin >> val;
        outputs.push_back(val);

    }

    // Number of test cases
    cin >> t;
    // Input all test cases
    for(int i = 0; i < t; i++){

        vector<double> test;
        double val;

        for(int j = 0; j <= f; j++){
            // Initializing first feature as 1.0, which would multiply with theta0 and form a constant
            if( j == 0) test.push_back(1.0);

            // Inputting the input values for this test case
            else{
                cin >> val;
                test.push_back(val);
            }
        }

        // Pushing the whole set of inputs for this test case in the tests matrix
        tests.push_back(test);
        // Initializing the output/result of this test case and pushing in predictions vector
        val = 0.0;
        predictions.push_back(val);

    }


    //showData();

    //cout << "Current error = " << RMSerror() << endl;
    //for(int i = 0; i < 100000; i++) regressionIterate();
    //while(RMSerror() > max_allowed_RMS_error) regressionIterate();

    previous_RMS_error = RMSerror();
    regressionIterate();

    //cout << "predictions for test cases : " ;
    for(int i = 0; i < tests.size(); i++) cout << predict(tests[i]) << "\n";
    //showData();

    //cout<<endl<<RMSerror();

    return 0;
}
