#include<bits/stdc++.h>
using namespace std;

class Connection {
public:
	double weight;
	double deltaWeight;
	Connection() {
		weight = rand() / double(RAND_MAX);
	}
};

class Neuron {
public:
	Neuron(){};
	void makeConnections(int number_of_connections) {
		for (int i = 0; i < number_of_connections; i++)
			output_weights.push_back(Connection());
	}
	void setOutputValue(double input_value) {


	}
	void feedForward() {


	}

private:
	vector<Connection> output_weights;
};

class Net {
public:
	Net(int total_layers...) {
		va_list args;
		va_start(args, total_layers);
		for (int i = 0; i < total_layers; i++) {
			int layer_size = va_arg(args, int);
			vector<Neuron*> layer;
			for (int j = 0; j <= layer_size; j++) {
				Neuron * n = new Neuron();
				layer.push_back(n);
			}
			layers.push_back(layer);

				if (i) makeConnections(i - 1, layer_size + 1);  // Making connections from all neurons of last layer
			}
			va_end(args);
		}

		void feedForward(...) {
			va_list args;
			va_start(args, layers[0].size() - 1);
			for (int i = 0; i < layers[0].size() - 1; i++) {
				double input_value = va_arg(args, double);
				layers[0][i] -> setOutputValue(input_value);
			}
			va_end(args);
			for (int i = 1; i < layers.size(); i++) {
				for (int j = 0; j < layers[i].size(); j++) layers[i][j] -> feedForward();
			}
	}

	void describe() {
		cout << "Neural Net Description: \n_______________\nTotal Layers: " << layers.size() << "\n";
		for (int i = 0; i < layers.size(); i++) {
			cout << "Layer #" << i + 1 << ": " << layers[i].size() << " neurons\n";
		}
		cout << "_______________\n";
	}

private:
	vector<vector<Neuron*> > layers;

	void makeConnections(int layer_number, int number_of_connections) {
		for (int i = 0; i < layers[layer_number].size(); i++)
			layers[layer_number][i] -> makeConnections(number_of_connections);
	}
};

int main()
{
	Net * n = new Net(3, 2, 2, 3);
	n -> feedForward(0.83, 0.98);
	n -> describe();
}
