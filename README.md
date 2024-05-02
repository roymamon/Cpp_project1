# Cpp_project1
first project in c++

I.D: 322623323
mail: mamon8521@gmail.com 

this is a first project in systems programming b course
regarding graphs and algorithms in c++.

Graph.hpp: header

constructor and destructor: provides a default constructor and destructor.

loadGraph: loads a graph from a given adjacency matrix and  checks wether the matrix is square, throws exception if it isnt.

printGraph: prints the number of vertices and edges in the graph.

size: returns the number of vertices in the graph.

getAdjacencyMatrix: returns the adjacency matrix.

Graph.cpp: implementation

loadGraph: gets an adjacency matrix as input and sets it as the current graph representation, throws exception using stdexept.

printGraph: returns the number of rows in an adjacency matrix(which is also the number of vertices), and returns
non zero integers in the matrix(which is the number of edges).

size: returns the number of rows in the matrix.

getAdjacencyMatrix: returns the matrix.

Algorithms.hpp: header

isConnected: checks if all vertices in the graph are reachable from each other.

shortestPath: returns the shortest path between two vertices.

isContainsCycle: checks if there is a cycle in the graph and prints it if one exists.

isBipartite: checks if a graph can be split into two disjoint sets, returns them if they exist.

negativeCycle: checks if there is a negative cycle in the graph and prints it if one exists.

Algorithms.cpp: implementation

isConnected: gets a graph and return true/false wether the graph is connected or not using DFS algorithm.

shortestPath: gets a graph, start and end point and returns
the shortest path using Dijkstra algorithm.

isContainsCycle: gets a graph and returns a graph if one exists or 0 or not, using DFS algorithm(more specifically - checks if there is a back edge).

isBipartite: gets a graph and returns the disjoint sets, using BFS algorithm + coloring during the algorithm to 2 colors.

negativeCycle: gets a graph and returns a negativeCycle using BF algorithm(relaxing n-1 times and then trying to relax one more time).

Makefile: 

using a makefile inorder to make the compilation process easier for us. 
using g++ and mainly making 2 exe files - Test, Demo.

Demo.cpp:

a demo file given by the university inorder to better understand how the functions should work and what should be printed using several examples.
i also added to the given demo that examples i made from Test.cpp inorder to also see the prints itself.

Test.cpp:

tests that were given to us and also tests i made myself checking the functions on different graphs,
using asserts( include cassert ).


