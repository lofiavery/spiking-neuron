#include <vector>

class Neuron {
    public:
    std::vector<int> connections;
    std::vector<float> weights;
    float activation = 0;
    float set_activation(float a) {activation = a;}
    Neuron(std::vector<int> connectionIds, std::vector<float> weights) : connections(connectionIds), weights(weights) {}
    Neuron() {}

};