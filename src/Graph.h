#include <unordered_map>
#include "Neuron.h"

class Graph {
    public:
    std::unordered_map<int, Neuron> neurons;
    int total_neurons;
    int max_connections;
    int output_id;

    Graph(int n_neurons, int max_connections); 
    Graph(){}
    void print_graph();
    void save_graph(std::string outfile);

    void load_input(std::vector<float>&);

    void graph_step();
    void print_output();
    float get_output_activation();

};