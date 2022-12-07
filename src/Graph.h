#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using std::map;
using std::vector;
using std::queue;
using std::string;
using std::cout;
using std::cin;
using std::endl;


class Graph {
    int V; //number of vertices in the graph
    vector<vector<int>> adjMatrix;  //adjacency matrix

    public: 
        Graph(int v);   //constructor
        ~Graph();   //destructor
        void addEdge(int v, int w, int weight); //adds edge to graph
        
        int findShortestPathBFS(int s, int d); //shortest path from source vertex to destination
        int printBFS(vector<int> & parent, int s, int d);    //prints shortest path from source to destination
        vector<int> dijkstra(int src, int dest);  //dijkstra's method, which calls getMin as a helper
        int getMin(int distance[], bool visited[]);
        vector<int> printDijkstra(int distance[], int parent[], int d);
        
        void printAdjencyMatrix();
    
};
