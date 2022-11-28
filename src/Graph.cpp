#include "Graph.h"

map<string, int> mapDistanceGraph(vector<int> & v, map<int, string> & m) {  //might move to utils file
    map<string, int> result;
    for(size_t i = 0; i < v.size(); i++) {
        if(m.find(i) != m.end()) {
            result[m.find(i)->second] = v[i];
        }
    }
    return result;
}

void printDistanceMap(map<string, int> & m) {
    for(auto itr = m.begin(); itr != m.end(); ++itr) {
        cout << itr->first << " " << itr->second << endl;
    }
    cout << "\n" << endl;
}


//This is a weighted, directed graph implementation if edges are weighted 1 or 2
Graph::Graph(int v) {
    this->V = v;
    adjList = new list<int>[2*v];
    // adjList.resize(v+1, vector<int>(v+1));
    cost.resize(v+1, vector<int>(v+1));
    for(size_t i = 0; i < cost.size(); i++) {
        for(size_t j = 0; j < cost[i].size(); j++) {
            cost[i][j] = 1;
            //adjList[i][j] = -1;
        }
    }
}

Graph::~Graph() {   //work on this
    for(size_t i = 0; i < cost.size(); i++) {
        for(size_t j = 0; j < cost[i].size(); j++) {
            cost[i][j] = 1;
        }
    }
    // for(size_t u = 0; u < adjList.size(); u++) { for adjacency matrix 
    //     for(size_t v = 0; v < adjList[u].size(); v++) {
    //         adjList[u][v] = -1;
    //     }
    // }
    delete[] adjList;
}

void Graph::addEdge(int v, int w, int weight) {
    adjList[v].push_back(w);
    adjList[w].push_back(v);
    cost[v][w] = weight;
}

int Graph::printBFS(vector<int> & parent, int s, int d) {
    static int pos = 0;
    
    if(parent[s] == -1) {
        cout << "Shortest Path Between " << s << " and " << d << " is " << " ";
        cout << endl;
        return pos;
    }
    printBFS(parent, parent[s], d);
    
    pos++;
    if(s < V) {
        cout << s << " ";
    }
    cout << endl;
    return pos;
}

int Graph::findShortestPathBFS(int s, int d) {
    vector<bool> visited(2*V, false);
    vector<int> parent(2*V, -1);

    queue<int> q;    //create a queue for BFS, and mark current node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    list<int>::iterator it; //comment out for adjacency matrix

    while(!q.empty()) {
        int v = q.front();
        if(v == d) {
            return printBFS(parent, v, d);
        }
        q.pop();

        for(it = adjList[v].begin(); it != adjList[v].end(); ++it) {    //Get all adjacent vertices to v, and if one has not been visited, mark visited and enqueue
            if(!visited[*it]) {
                visited[*it] = true;
                q.push(*it);
                parent[*it] = v;
            }
        }
        // for(size_t it = 0; it < adjList[v].size(); it++) {   //this works for adjacency matrix instead of list
        //     if(!visited[adjList[v][it]]) {
        //         visited[adjList[v][it]] = true;
        //         q.push(adjList[v][it]);
        //         parent[adjList[v][it]] = v;
        //     }
        // }

    }
}

int Graph::getMin(int distance[], bool visited[]) {
    int minNode = 0;
    int minValue = INT_MAX;
    for(int i = 0; i < V; i++) {
        if(!visited[i] && distance[i] < minValue) {
            minValue = distance[i];
            minNode = i;
        }
    }
    return minNode;
}

vector<int> Graph::dijkstra(int src) { //should also have destination included in this algorithm->need to get around to doing this
    int size = 2*V;
    int parent[size], distance[size];
    bool visited[size];

    for(int index = 0; index < size; index++) {
        visited[index] = false;
    }

    std::fill(distance, distance + V, INT_MAX);
    distance[src] = 0;
    parent[src] = -1;

    for(int g = 0; g < V-1; g++) {
        int u = getMin(distance, visited);
        visited[u] = true;
        for(int v = 0; v < V; v++) {
            if(!visited[v] && cost[u][v] != INT_MAX && (distance[v] > distance[u] + cost[u][v])) {
                distance[v] = distance[u] + cost[u][v];
                parent[v] = u;
            }
        }
    }
    vector<int> v = printDijkstra(distance, parent);
    return v;
}

vector<int> Graph::printDijkstra(int distance[], int parent[]) {
    vector<int> distanceVector;
    for(int i = 0; i < V; i ++) {
        int pos = parent[i];
        cout<<i << " <- ";
        while(pos != -1) {
            cout<< pos << " <- ";
            pos = parent[pos];
        }
        cout << endl;
        cout<< "::::Distance = " << distance[i];
        cout<< endl;
        distanceVector.push_back(distance[i]);
    }
    cout << "\n" << endl;
    return distanceVector;
}

void Graph::printCostMatrix() {
    for(size_t i = 0; i < cost.size(); i++) {
        for(size_t j = 0; j < cost[i].size(); j++) {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n" << endl;
}
