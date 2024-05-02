#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

//I.D: 322623323
//mail: mamon8521@gmail.com 


using namespace std;

namespace ariel {

    const std::vector<std::vector<int>>& Graph::getAdjacencyMatrix() const {
        return adjacencyMatrix;
    }

    void Graph::loadGraph(const vector<vector<int>>& adjacencyMatrix) {
        if (adjacencyMatrix.empty() || adjacencyMatrix.size() != adjacencyMatrix[0].size()) {
            throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
        this->adjacencyMatrix = adjacencyMatrix;
    }

    void Graph::printGraph() const {
        cout << "Graph with " << size() << " vertices and ";
        int edges = 0;
        for (const auto& row : adjacencyMatrix) {
            for (int val : row) {
                if(val != 0){
                edges ++;
            }
        }
        }
        
        cout << edges << " edges." << endl;
    }

    int Graph::size() const {
        return adjacencyMatrix.size();
    }

} 
