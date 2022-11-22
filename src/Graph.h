#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <algorithm>
#include <map>

using std::map;
using std::vector;
using std::pair;
using std::queue;
using std::list;
using std::stack;
using std::cout;
using std::cin;
using std::endl;

class Graph {
    int V, cost[100][100];  //number of vertices in the graph
    list<int> *adjList;    //adjacency lists

    public: 
        Graph(int v);   //constructor
        ~Graph();
        void addEdge(int v, int w, int weight); //adds edge to graph
        int findShortestPathBFS(int s, int d); //shortest path from source vertex to destination
        int printShortestPath(int parent[], int s, int d);    //prints shortest path from source to destination
        void dijkstra(int src);
        int getMin(int distance[], bool visited[]);
        void printDijkstra(int distance[], int parent[]);
        
};
