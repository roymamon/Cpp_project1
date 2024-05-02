#include <cassert>
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <stdexcept>
#include <iostream>

//I.D: 322623323
//mail: mamon8521@gmail.com 


using namespace std;



void test_isConnected() {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    assert(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    assert(ariel::Algorithms::isConnected(g) == false);
}

void test_shortestPath() {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    assert(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    assert(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}

void test_isContainsCycle() {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    assert(ariel::Algorithms::isContainsCycle(g) == "0");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    assert(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 2->1->0->2");
}

void test_isBipartite() {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    assert(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}.");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    assert(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    assert(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}.");
}

void test_invalidGraph() {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5} // Non-square matrix
    };

    // Test to catch exception during graph loading
    assert(( [&]() { 
        try { 
            g.loadGraph(graph); // This is where the exception is expected
            return false; // If loadGraph succeeds, return false (assertion fails)
        } catch (const std::invalid_argument& e) { 
            std::cout << "Caught exception: " << e.what() << std::endl;
            return true; // If exception is caught, return true (assertion passes)
        } catch (...) {
            std::cout << "Caught an unexpected type of exception." << std::endl;
            return true; // Handle any other types of exceptions
        } 
    })());
}


void test_negativeCycle() {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 2, 0, 0},
        {0, 0, -1, 0},
        {0, 0, 0, 3},
        {0, 0, 1, 0}};
    g.loadGraph(graph);
    assert(ariel::Algorithms::negativeCycle(g) == "no negative cycle");

    vector<vector<int>> graph2 = {
        {0, 2, 0},
        {0, 0, -5},
        {1, 0, 0}};
    g.loadGraph(graph2);
    assert(ariel::Algorithms::negativeCycle(g) == "The negative cycle is: 1->2->0->1");
}

void test_all1() {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, -3, 0, 0},  
        {0, 0, -2, 0},  
        {0, 0, 0, 4},
        {0, 0, 0, 0}
    };
    g.loadGraph(graph);
    assert(ariel::Algorithms::isConnected(g) == true);
    assert(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");
    assert(ariel::Algorithms::isContainsCycle(g) == "0");
    assert(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}.");
    assert(ariel::Algorithms::negativeCycle(g) == "no negative cycle");



}

void test_all2() {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 2, 0, 0},  
        {0, 0, 4, 15},  
        {0, 1, 0, 5},
        {0, -12, 1, 0}
    };
    g.loadGraph(graph);
    assert(ariel::Algorithms::isConnected(g) == true);
    assert(ariel::Algorithms::shortestPath(g, 1, 3) == "1->2->3");
    assert(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 3->2->1->3");
    assert(ariel::Algorithms::isBipartite(g) == "0");
    assert(ariel::Algorithms::negativeCycle(g) == "The negative cycle is: 2->3->1->2");
}

void test_all3() {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 0, 0, 6, 0, 0},  
        {0, 0, 0, 0, -4, 0},  
        {0, 0, 0, 0, 0, -2},
        {7, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };
    g.loadGraph(graph);
    assert(ariel::Algorithms::isConnected(g) == false);
    assert(ariel::Algorithms::shortestPath(g, 1, 4) == "1->4");
    assert(ariel::Algorithms::isContainsCycle(g) == "0");
    assert(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1, 2}, B={3, 4, 5}.");
    assert(ariel::Algorithms::negativeCycle(g) == "no negative cycle");
}

void test_all4() {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 3, -2, 0, 0},
        {1, 0, -1, 0, 0},
        {4, 7, 0, 1, 0},
        {0, 0, 5, 0, 0},
        {0, 0, 0, 3, 0}
    };
    g.loadGraph(graph);
    assert(ariel::Algorithms::isConnected(g) == false);
    assert(ariel::Algorithms::shortestPath(g, 0, 2) == "0->2");
    assert(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 2->1->0->2");
    assert(ariel::Algorithms::isBipartite(g) == "0");
    assert(ariel::Algorithms::negativeCycle(g) == "no negative cycle");
}

void test_all5() {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 0, 0, 13},  
        {0, 0, 7, 0},  
        {0, -6, 0, 0},
        {-12, 0, 0, 0}
    };
    g.loadGraph(graph);
    assert(ariel::Algorithms::isConnected(g) == false);
    assert(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");
    assert(ariel::Algorithms::isContainsCycle(g) == "0");
    assert(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1}, B={3, 2}.");
    assert(ariel::Algorithms::negativeCycle(g) == "no negative cycle");
}


int main() {
    test_isConnected();
    test_shortestPath();
    test_isContainsCycle();
    test_isBipartite();
    test_invalidGraph();
    test_negativeCycle();
    test_all1();
    test_all2();
    test_all3();
    test_all4();
    test_all5();



    return 0;
}
