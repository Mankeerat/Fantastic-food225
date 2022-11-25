#include "Graph.h"
//This is a weighted, directed graph implementation if edges are weighted 1 or 2
Graph::Graph(int v) {
    this->V = v;
    adjList = new list<int>[2*v];
    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 50; j++) {
            cost[i][j] = 1;
        }
    }
}

Graph::~Graph() {
    for(int i = 0; i < V; i++) {
        //delete[] adjList[i];
        V = 0;
    }
    delete adjList;
}

void Graph::addEdge(int v, int w, int weight) {
    // if(weight != 1) {
    //     adjList[v].push_back(v+V);  //splits edge weighted 2 into 2 edges weighted 1
    //     adjList[v+V].push_back(w);
    // } else {
    //     adjList[v].push_back(w);
    // }
    adjList[v].push_back(w);
    adjList[w].push_back(v);
    cost[v][w] = weight;
}

int Graph::printBFS(int parent[], int s, int d) {
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
    bool *visited = new bool[2*V];
    int *parent = new int[2*V];

    for(int i = 0; i < 2*V; i++) {
        visited[i] = false;
        parent[i] = -1;
    }

    queue<int> q;    //create a queue for BFS, and mark current node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    list<int>::iterator it;

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

    }
    delete[] visited;
    delete[] parent;
    visited = nullptr;
    parent = nullptr;
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

void Graph::dijkstra(int src) { //should also have destination included in this algorithm->need to get around to doing this
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
            if(!visited[v] && cost[u][v] != 9999 && (distance[v] > distance[u] + cost[u][v])) {
                distance[v] = distance[u] + cost[u][v];
                parent[v] = u;
            }
        }
    }
    printDijkstra(distance, parent);
}

void Graph::printDijkstra(int distance[], int parent[]) {
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
    }
}

// void Graph::printCost() {
//     cout << "Testing Cost Matrix: " << endl;
//     for(size_t i = 0; i < 50; i++) {
//         for(size_t j = 0; j < 50; j++) {
//             cout << this->cost[i][j] << " ";
//         }
//         cout << endl;
//     }
// }