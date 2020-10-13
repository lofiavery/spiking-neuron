#include "Graph.h"
#include <cstdio>
#include <iostream>
#include <random>
#include <fstream>
#include <unordered_map>

using namespace std;
Graph::Graph(int n_neurons, int m_connections) : total_neurons(n_neurons), max_connections(m_connections), output_id(n_neurons - 1) {
    for (int i = 0; i < total_neurons; i++) {
        vector<int> connections;
        vector<float> weights;
        int num_connections = rand() % max_connections + 1;

        for (int j = 0; j < num_connections; j++) {
            int connection_id = rand() % n_neurons;
            connections.push_back(connection_id);
            float weight = ((float) rand()) / (float) RAND_MAX;
            weight = weight * 2 - 1;
            weights.push_back(weight);
        }
        neurons[i] = Neuron(connections, weights);
    }
}

void Graph::load_input(std::vector<float>& input) {
    size_t size = input.size();
    for (int i = 0; i < size; i++) {
        neurons[i].activation = input[i];
    }
}

void Graph::graph_step() {
    unordered_map<int, float> activations;
    float activation = 0;
    for (auto &f : neurons) {
        // compute weighted activations and relu;
        for (int i = 0; i < f.second.connections.size(); i++) {
            activation += f.second.weights[i] * neurons[f.second.connections[i]].activation;
        }
        activations[f.first] = min(max(activation, 0.0f), 10.0f);
    }

    for (auto &f : neurons) {
        f.second.activation = activations[f.first];

    }
}

void Graph::print_graph() {
    for (auto &f : neurons) {
        cout << "Neuron " << f.first << endl;
        for (int i = 0; i < f.second.connections.size(); i++) {
            cout << f.second.connections[i] << " " << f.second.weights[i] << endl;
        }
        cout << endl;
    }
}

float Graph::get_output_activation() {
    return neurons[output_id].activation;
}

void Graph::print_output() {
    for (auto &f : neurons) {
        cout << f.first << " " << f.second.activation << endl;
    }
}

// Json output
void Graph::save_graph(string outfile) {
    ofstream file;
    file.open(outfile);
    file << "[" << endl;

    string delim = "";
    for (auto &f : neurons) {
        file << delim;
        file << "{" << endl;
        file << "\"id\":" << f.first << "," << endl;
        file << "\"connections\": [";
        for (int i = 0; i < f.second.connections.size(); i++) {
            file << f.second.connections[i]; // << ","; // << f.second.weights[i];
            if (i < f.second.connections.size() - 1) 
                file << ",";
        }
        file << "]" << endl;
        file << "}";
        delim = ",\n";
    }
    file << "]" << endl;
    file.close();


}