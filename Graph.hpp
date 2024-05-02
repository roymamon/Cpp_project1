#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <string>

//I.D: 322623323
//mail: mamon8521@gmail.com 


namespace ariel {

    class Graph {
    public:
        Graph() = default;
        ~Graph() = default;

        void loadGraph(const std::vector<std::vector<int>>& adjacencyMatrix);
        void printGraph() const;
        int size() const;
        const std::vector<std::vector<int>>& getAdjacencyMatrix() const; // New function declaration


    private:
        std::vector<std::vector<int>> adjacencyMatrix;
    };

} 

#endif 
