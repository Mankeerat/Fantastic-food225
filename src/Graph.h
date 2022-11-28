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

map<string, int> mapDistanceGraph(vector<int> & v, map<int, string> & m);
void printDistanceMap(map<string, int> & m);


class Graph {
    int V; //number of vertices in the graph
    vector<vector<int>> cost;   //cost matrix
    list<int> *adjList;    //adjacency lists ->think I will have to create a list of edges instead of a list of ints, otherwise our Dikstra's will not work
    //vector<vector<int>> adjList;

    public: 
        Graph(int v);   //constructor
        ~Graph();
        void addEdge(int v, int w, int weight); //adds edge to graph
        
        int findShortestPathBFS(int s, int d); //shortest path from source vertex to destination
        int printBFS(vector<int> & parent, int s, int d);    //prints shortest path from source to destination
        vector<int> dijkstra(int src);
        int getMin(int distance[], bool visited[]);
        vector<int> printDijkstra(int distance[], int parent[]);
        
        void printCostMatrix();
    
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
