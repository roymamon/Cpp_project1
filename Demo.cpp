/*
 * Demo program for Exercise 2.
 * Author: Benjamin Saldman.
 */

//I.D: 322623323
//mail: mamon8521@gmail.com 


#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    ariel::Graph g;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph); // Load the graph to the object.
    cout << "graph number 1:" << endl;
    g.printGraph();                   //w                 // Should print: "Graph with 3 vertices and 4 edges."
    cout << Algorithms::isConnected(g) << endl; //w      // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 2) << endl; //w // Should print: 0->1->2.
    cout << Algorithms::isContainsCycle(g) << endl;  //w  // Should print: "0" (false).
    cout << Algorithms::isBipartite(g) << endl;     //w   // Should print: "The graph is bipartite: A={0, 2}, B={1}."
    cout << endl;

    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.
    cout << "graph number 2:" << endl;
    g.printGraph();         //w       // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms::isConnected(g) << endl;   //w   // Should print: "0" (false).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; //w // Should print: "-1" (there is no path between 0 and 4).
    cout << Algorithms::isContainsCycle(g) << endl; //w   // Should print: "The cycle is: 0->1->2->0".
    cout << Algorithms::isBipartite(g) << endl;   //w   // Should print: "0" (false).
    cout << endl;

    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3); // Load the graph to the object.
    cout << "graph number 3:" << endl;
    g.printGraph();   //w            // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms::isConnected(g) << endl;  //w    // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; //w // Should print: 0->1->2->3->4.
    cout << Algorithms::isContainsCycle(g) << endl;  //w  // Should print: "0" (false).
    cout << Algorithms::isBipartite(g) << endl;     //w   // Should print: "The graph is bipartite: A={0, 2, 4}, B={1, 3}."
    cout << endl;

    // 5x4 matrix that reprsents invalid graph.
   cout << "graph number 4:" << endl;

    vector<vector<int>> graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    try
    {
        g.loadGraph(graph4); // Load the graph to the object.
  
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl << endl; //w // Should print: "Invalid graph: The graph is not a square matrix."
    }
    

    
    vector<vector<int>> graph5 = {
        {0, 2, 0, 0},
        {0, 0, -1, 0},
        {0, 0, 0, 3},
        {0, 0, 1, 0}};
    g.loadGraph(graph5);
    cout << "graph number 5:" << endl;
    g.printGraph();
    cout << Algorithms::negativeCycle(g) << endl; //Should print: "no negative cycle"
    cout << endl;

    vector<vector<int>> graph6 = {
        {0, 2, 0},
        {0, 0, -5},
        {1, 0, 0}};
    g.loadGraph(graph6);
    cout << "graph number 6:" << endl;
    g.printGraph();
    cout << Algorithms::negativeCycle(g) << endl; //Should print: "The negative cycle is: 1->2->0->1"
    cout << endl;

    vector<vector<int>> graph7 = {
        {0, -3, 0, 0},  
        {0, 0, -2, 0},  
        {0, 0, 0, 4},
        {0, 0, 0, 0}
            
    };
    g.loadGraph(graph7); // Load the graph to the object.
    cout << "graph number 7:" << endl;
    g.printGraph();  // This should print: "Graph with 4 vertices and 3 edges."
    cout << Algorithms::isConnected(g) << endl;  // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 3) << endl;  // Should print: "0->1->2->3".
    cout << Algorithms::isContainsCycle(g) << endl;  // Should print: "0" (false).
    cout << Algorithms::isBipartite(g) << endl;  // Should print: "The graph is bipartite: A={0, 2}, B={1, 3}."
    cout << Algorithms::negativeCycle(g) << endl; // Should print: "no negative cycle"
    cout << endl;

    vector<vector<int>> graph8 = {
        {0, 2, 0, 0},  
        {0, 0, 4, 15},  
        {0, 1, 0, 5},
        {0, -12, 1, 0}
            
    };
    g.loadGraph(graph8); // Load the graph to the object.
    cout << "graph number 8:" << endl;
    g.printGraph();  // This should print: "Graph with 4 vertices and 7 edges."
    cout << Algorithms::isConnected(g) << endl;  // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 1, 3) << endl;  // Should print: "1->2->3".
    cout << Algorithms::isContainsCycle(g) << endl;  // Should print: "The cycle is: 3->2->1->3".
    cout << Algorithms::isBipartite(g) << endl;  // Should print: "0"
    cout << Algorithms::negativeCycle(g) << endl; // Should print: "The negative cycle is: 2->3->1->2"
    cout << endl;

    vector<vector<int>> graph9 = {
        {0, 0, 0, 6, 0, 0},  
        {0, 0, 0, 0, -4, 0},  
        {0, 0, 0, 0, 0, -2},
        {7, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
            
    };
    g.loadGraph(graph9); // Load the graph to the object.
    cout << "graph number 9:" << endl;
    g.printGraph();  // This should print: "Graph with 6 vertices and 5 edges."
    cout << Algorithms::isConnected(g) << endl;  // Should print: "0" (false).
    cout << Algorithms::shortestPath(g, 1, 4) << endl;  // Should print: "1->4".
    cout << Algorithms::isContainsCycle(g) << endl;  // Should print: "0".
    cout << Algorithms::isBipartite(g) << endl;  // Should print: "The graph is bipartite: A={0, 1, 2}, B={3, 4, 5}."
    cout << Algorithms::negativeCycle(g) << endl; // Should print: "no negative cycle"
    cout << endl;

    vector<vector<int>> graph10 = {
        {0, 3, -2, 0, 0},
        {1, 0, -1, 0, 0},
        {4, 7, 0, 1, 0},
        {0, 0, 5, 0, 0},
        {0, 0, 0, 3, 0}
            
    };
    g.loadGraph(graph10); // Load the graph to the object.
    cout << "graph number 10:" << endl;
    g.printGraph();  // This should print: "Graph with 5 vertices and 9 edges."
    cout << Algorithms::isConnected(g) << endl;  // Should print: "0" (true).
    cout << Algorithms::shortestPath(g, 0, 2) << endl;  // Should print: "0->2".
    cout << Algorithms::isContainsCycle(g) << endl;  // Should print: "The cycle is: 2->1->0->2".
    cout << Algorithms::isBipartite(g) << endl;  // Should print: "0"
    cout << Algorithms::negativeCycle(g) << endl; // Should print: "no negative cycle"
    cout << endl;

    vector<vector<int>> graph11 = {
        {0, 0, 0, 13},  
        {0, 0, 7, 0},  
        {0, -6, 0, 0},
        {-12, 0, 0, 0}
            
    };
    g.loadGraph(graph11); // Load the graph to the object.
    cout << "graph number 11:" << endl;
    g.printGraph();  // This should print: "Graph with 4 vertices and 4 edges."
    cout << Algorithms::isConnected(g) << endl;  // Should print: "0" (true).
    cout << Algorithms::shortestPath(g, 0, 2) << endl;  // Should print: "-1".
    cout << Algorithms::isContainsCycle(g) << endl;  // Should print: "0".
    cout << Algorithms::isBipartite(g) << endl;  // Should print: "The graph is bipartite: A={0, 1}, B={3, 2}."
    cout << Algorithms::negativeCycle(g) << endl; // Should print: "no negative cycle"
    cout << endl;
}

