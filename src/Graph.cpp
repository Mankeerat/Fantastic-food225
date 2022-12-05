#include "Graph.h"


Graph::Graph(int v) {
    this->V = v;
    adjMatrix.resize(v+1, vector<int>(v));
    cost.resize(v+1, vector<int>(v));
    for(size_t i = 0; i < cost.size(); i++) {
        for(size_t j = 0; j < cost[i].size(); j++) {
            cost[i][j] = 1;
            adjMatrix[i][j] = -1;
        }
    }
}

Graph::~Graph() {   //work on this
    for(size_t i = 0; i < cost.size(); i++) {
        for(size_t j = 0; j < cost[i].size(); j++) {
            cost[i][j] = 1;
        }
    }
    for(size_t u = 0; u < adjMatrix.size(); u++) {
        for(size_t v = 0; v < adjMatrix[u].size(); v++) {
            adjMatrix[u][v] = -1;
        }
    }
}

void Graph::addEdge(int v, int w, int weight) {
    adjMatrix[v][w] = weight;   //theses can all either be 1, weight, or mix based on implementation.
    adjMatrix[w][v] = weight;
    cost[v][w] = weight;
    cost[w][v] = weight;    //this may not be necessary... depends on how we want to do this
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
    vector<bool> visited(adjMatrix.size(), false);
    vector<int> parent(adjMatrix.size(), -1);

    queue<int> q;    //create a queue for BFS, and mark current node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    while(!q.empty()) {
        int v = q.front();
        if(v == d) {
            return printBFS(parent, v, d);
        }
        q.pop();

        for(size_t it = 0; it < adjMatrix[v].size(); it++) {   //this works for adjacency matrix instead of list
            if(!visited[it] && adjMatrix[v][it] != -1) {
                visited[it] = true;
                q.push(it);
                parent[it] = v;
            }
        }
    }
    return -1;
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

void Graph::printAdjencyMatrix() {
    for(size_t i = 0; i < adjMatrix.size(); i++) {
        for(size_t j = 0; j < adjMatrix[i].size(); j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n" << endl;
}
