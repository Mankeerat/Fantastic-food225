#pragma once
#include <iostream>
#include <string>
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
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Graph {
    int V, cost[100][100];  //number of vertices in the graph, and cost matrix
    list<int> *adjList;    //adjacency lists ->think I will have to create a list of edges instead of a list of ints, otherwise our Dikstra's will not work
    //vector<vector<Edge>> adjList; //could also use this implementation

    public: 
        Graph(int v);   //constructor
        ~Graph();
        void addEdge(int v, int w, int weight); //adds edge to graph
        int findShortestPathBFS(int s, int d); //shortest path from source vertex to destination
        int printBFS(int parent[], int s, int d);    //prints shortest path from source to destination
        void dijkstra(int src);
        int getMin(int distance[], bool visited[]);
        void printDijkstra(int distance[], int parent[]);
    
};

struct Vertex {
    string name;
    Vertex() {name = " ";}
    Vertex(string s) : name(s){}
    ~Vertex() {name = " ";}
    void setVertexName(string s) {this->name = s;}
    string getVertexName() {return this->name;}
};

struct Edge {
    int weight;
    Vertex src;
    Vertex dest;
    Edge(Vertex v1, Vertex v2, int w) : weight(w), src(v1), dest(v2){}
    ~Edge() {
        this->weight = 0;
        this->src = Vertex();
        this->dest = Vertex();
    }
    void setEdgeWeight(int w) {this->weight = w;}
    int getEdgeWeight() {return this->weight;}
    Vertex getSourceVertex() {return this->src;}
    Vertex getDestVertex() {return this->dest;}
};