#include<vector>
#include<iostream>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include <stdlib.h>

using namespace std;

struct Connection{

    double weight;
    double deltaWeight;

};

class Neuron;

typedef vector<Neuron> Layer;

class Neuron{

    public:
        Neuron(unsigned numOutputs, unsigned myIndex);
        void setOutputVal(double Val){ m_outputVal = Val; }
        double getOutputVal(void){ return m_outputVal; }
        void feedForward(Layer &prevLayer);
        void calcOutputGradients(double targetVal);
        void calcHiddenGradients(Layer &nextLayer);
        void updateInputWeights(Layer &prevLayer);

    private:
        static double randomWeight(void){ return rand() / double(RAND_MAX); }
        static double transferFunction(double x);
        static double transferFunctionDerivative(double x);
        double sumDOW(Layer &nextLayer);

        double m_outputVal;
        vector<Connection> m_outputWeights;

        unsigned m_myIndex;
        double m_gradient;

        static double eta;
        static double alpha;

};

Neuron::Neuron(unsigned numOutputs, unsigned myIndex){

    for(unsigned c = 0; c < numOutputs; c++){
        m_outputWeights.push_back(Connection());
        m_outputWeights.back().weight = randomWeight();
        //cout<<"given weight "<<m_outputWeights.back().weight<<endl;
    }

    m_myIndex = myIndex;
}

void Neuron::feedForward(Layer &prevLayer){

    double sum = 0.0;

    for(unsigned n = 0; n < prevLayer.size(); n++){
        sum += (prevLayer[n].getOutputVal()) * (prevLayer[n].m_outputWeights[m_myIndex].weight);
    }

    m_outputVal = Neuron::transferFunction(sum);

}

double Neuron::transferFunction(double x){

    return tanh(x);

}

double Neuron::transferFunctionDerivative(double x){

    return 1.0 - x * x;

}

void Neuron::calcOutputGradients(double targetVal){

    double delta = targetVal - m_outputVal;
    m_gradient = delta * Neuron::transferFunctionDerivative(m_outputVal);

}

void Neuron::calcHiddenGradients(Layer &nextLayer){

    double dow = sumDOW(nextLayer);
    m_gradient = dow * Neuron::transferFunctionDerivative(m_outputVal);

}

double Neuron::sumDOW(Layer &nextLayer){

    double sum = 0.0;

    for(unsigned n = 0; n < nextLayer.size() - 1; n++){
        sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
    }

    return sum;

}

void Neuron::updateInputWeights(Layer &prevLayer){

    for(unsigned n = 0; n < prevLayer.size(); n++){
        Neuron &neuron = prevLayer[n];
        double oldDeltaWeight = neuron.m_outputWeights[m_myIndex].deltaWeight;

        double newDeltaWeight = eta * neuron.getOutputVal() * m_gradient + alpha * oldDeltaWeight;

        neuron.m_outputWeights[m_myIndex].deltaWeight = newDeltaWeight;
        neuron.m_outputWeights[m_myIndex].weight += newDeltaWeight;
    }

}

// Default Values
//double Neuron::eta = 0.15;
//double Neuron::alpha = 0.5;

// Test Values
double Neuron::eta = 0.01;
double Neuron::alpha = 0.01;


/****************************************************/

class Net{

    public:
        Net(const vector<unsigned> &topology);
        void feedForward(const vector<double> &inputVals);
        void backProp(const vector<double> &targetVals);
        void getResults(vector<double> &resultVals);

    private:
        vector<Layer> m_layers; // m_layers[layerNumber][NeuronNumber]
        double m_error;
        double m_recentAverageError;
        double m_recentAverageSmoothingFactor;

};

Net::Net(const vector<unsigned> &topology){

    unsigned numLayers = topology.size();
    for(unsigned layerNum = 0; layerNum < numLayers ; layerNum++){
        m_layers.push_back(Layer());
        unsigned numOutputs = layerNum < numLayers - 1 ? topology[layerNum + 1] : 0;

        for(unsigned neuronNum = 0; neuronNum <= topology[layerNum]; neuronNum++){
            m_layers.back().push_back(Neuron(numOutputs, neuronNum));
            //cout<<"pushed a neuron"<<endl;
        }

        m_layers.back().back().setOutputVal(1.0);
    }

}

void Net::feedForward(const vector<double> &inputVals){

    assert(inputVals.size() == m_layers[0].size() - 1);

    for(unsigned i = 0; i < inputVals.size() ; i++){
        m_layers[0][i].setOutputVal(inputVals[i]);
    }

    for(unsigned layerNum = 1; layerNum < m_layers.size(); layerNum++){
        Layer &prevLayer = m_layers[layerNum - 1];
        for(unsigned neuronNum = 0; neuronNum < m_layers[layerNum].size() - 1; neuronNum++){
            m_layers[layerNum][neuronNum].feedForward(prevLayer);
        }
    }

}

void Net::backProp(const vector<double> &targetVals){

    Layer &outputLayer = m_layers.back();
    m_error = 0.0;

    for(unsigned n = 0; n < outputLayer.size() - 1; n++){
        double delta = targetVals[n] - outputLayer[n].getOutputVal();
        m_error += delta * delta;
    }

    m_error /= outputLayer.size() - 1;
    m_error = sqrt(m_error);

    m_recentAverageError = (m_recentAverageError * m_recentAverageSmoothingFactor + m_error)
                            / (m_recentAverageSmoothingFactor + 1.0);


    for(unsigned n = 0; n < outputLayer.size() - 1; n++){
        outputLayer[n].calcOutputGradients(targetVals[n]);
    }

    for(unsigned layerNum = 0; layerNum < m_layers.size() - 2; layerNum++){
        Layer &hiddenLayer = m_layers[layerNum];
        Layer &nextLayer = m_layers[layerNum + 1];

        for(unsigned n = 0; n < hiddenLayer.size(); n++){
            hiddenLayer[n].calcHiddenGradients(nextLayer);
        }
    }

    for(unsigned layerNum = m_layers.size() - 1; layerNum > 0; layerNum--){
        Layer &layer = m_layers[layerNum];
        Layer &prevLayer = m_layers[layerNum - 1];

        for(unsigned n = 0; n < layer.size() - 1; n++){
            layer[n].updateInputWeights(prevLayer);
        }
    }


}

void Net::getResults(vector<double> &resultVals){

    resultVals.clear();

    for(unsigned n = 0; n < m_layers.back().size() - 1; n++){
        resultVals.push_back(m_layers.back()[n].getOutputVal());
    }

}


/*****************************************/

int main(){

    vector<unsigned> topology;

    topology.push_back(1);
    topology.push_back(4);
    topology.push_back(4);
    topology.push_back(4);
    topology.push_back(4);
    topology.push_back(4);

    Net myNet(topology);

    vector<double> inputVals;
    vector<double> targetVals;
    vector<double> resultVals;

    double cum_error = 0.0, error;
    int counter = 0, flag = 1;

    inputVals.clear();
    targetVals.clear();

    double i1, o1, o2, o3, o4;
    i1 = rand();
    i1 = i1/(4*(i1+rand()));
    o1 = i1;
    o2 = 2*i1;
    o3 = 3*i1;
    o4 = 4*i1;

    inputVals.push_back(i1);

    targetVals.push_back(o1);
    targetVals.push_back(o2);
    targetVals.push_back(o3);
    targetVals.push_back(o4);

    while(flag){



        myNet.feedForward(inputVals);
        myNet.backProp(targetVals);
        myNet.getResults(resultVals);

        error = 0.0;
        for(int i=0; i<targetVals.size(); i++) error += (targetVals[i] - resultVals[i]) * (targetVals[i] - resultVals[i]);
        error /= targetVals.size();
        error = sqrt(error);

        counter++;
        if(counter == 1) cum_error = 0.0;

        if(counter < 300){
            cum_error += (error*error);
        }
        else if(counter == 300) {
            cum_error += (error*error);
            cum_error /= 300;
            cum_error = sqrt(cum_error);

            system("cls");

            cout<<"Cumulative Error : "<<cum_error<<endl;

            if(cum_error < 0.01) flag = 0;
            counter = 0;
        }
    }
    cout<<"Neural net trained";

    //cout<<endl<<"Minimized the error value: "<<error;
/*
    for(int i=0; i<1000; i++){

        inputVals.clear();
        targetVals.clear();

        //double i1, i2, i3, i4, o1, o2, error=0.0;
        double i1, o1, o2, o3, o4;
        i1 = rand();
        i1 = i1/(4*(i1+rand()));
        o1 = i1;
        o2 = 2*i1;
        o3 = 3*i1;
        o4 = 4*i1;

        inputVals.push_back(i1);

        targetVals.push_back(o1);
        targetVals.push_back(o2);
        targetVals.push_back(o3);
        targetVals.push_back(o4);

        myNet.feedForward(inputVals);
        //if(error > 0.01) myNet.backProp(targetVals);
        myNet.getResults(resultVals);

        error = 0.0;
        for(int i=0; i<targetVals.size(); i++) error += (targetVals[i] - resultVals[i]) * (targetVals[i] - resultVals[i]);
        error /= targetVals.size();
        error = sqrt(error);

        cout<<error<<" | ";
        //if(error < 0.01) break;

    }
*/

}
