#include "Graph.h"
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

int main() {
    srand(time(NULL));
    vector<float> bars;
    vector<float> lines;
    
    for (int i = 0; i < 10*10; i++) {
        if (i % 2 == 0) bars.push_back(1.0);
        else bars.push_back(-1.0);
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            lines.push_back(-1.0f);
        }
        for (int j = 0; j < 10; j++) {
            lines.push_back(1.0f);
        }
    }


    Graph network(400, 3);
    network.load_input(bars);
    auto start = std::chrono::high_resolution_clock::now();
    // network.print_output();
    cout << endl;
    network.graph_step();
    for (int i = 0; i < 10; i++) {

    network.graph_step();
    cout << network.get_output_activation() << endl;
    }
    // network.print_output();

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken " << duration.count() << "mili" << endl;
    // network.print_graph();
    // network.save_graph("../log/test-output.json");

    // Graph network();
    return 0;
}