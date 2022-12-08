#include "Graph.h"


Graph::Graph(int v) {
    this->V = v;
    adjMatrix.resize(v, vector<int>(v));

    for(size_t i = 0; i < adjMatrix.size(); i++) {
        for(size_t j = 0; j < adjMatrix[i].size(); j++) {
            adjMatrix[i][j] = 0;
        }
    }

}

Graph::~Graph() {   //work on this
    for(size_t u = 0; u < adjMatrix.size(); u++) {
        for(size_t v = 0; v < adjMatrix[u].size(); v++) {
            adjMatrix[u][v] = 0;
        }
    }
}

void Graph::addEdge(int v, int w, int weight) {
    adjMatrix[v][w] = weight;   //theses can all either be 1, weight, or mix based on implementation.
    adjMatrix[w][v] = weight;
}
void Graph::setMatrix(vector<vector<int>> & m) {
    
}

int Graph::printBFS(vector<int> & parent, int s, int d) {
    static int pos = 0;
    cout<< endl;
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
            if(!visited[it] && adjMatrix[v][it] != 0) {
                visited[it] = true;
                q.push(it);
                parent[it] = v;
            }
        }
    }
    return -1;
}

int Graph::getMin(int distance[], bool visited[]) {
    int minNode = INT_MAX;
    int minValue = INT_MAX;
    for(int i = 0; i < V; i++) {
        if(!visited[i] && distance[i] < minValue) {
            minValue = distance[i];
            minNode = i;
        }
    }
    return minNode;
}

vector<int> Graph::dijkstra(int src, int dest) { //should also have destination included in this algorithm->need to get around to doing this
    int size = 2*V;
    int parent[size], distance[size];
    bool visited[size];

    for(int index = 0; index < size; index++) {
        visited[index] = false;
    }

    std::fill(distance, distance + V, INT_MAX);
    distance[src] = 0;
    parent[src] = -1;

    for(int i = 0; i < V-1; i++) {
        int u = getMin(distance, visited);
        visited[u] = true;
        for(int v = 0; v < V; v++) {
            int currDistance = distance[u] + adjMatrix[u][v];
            if(!visited[v] && adjMatrix[u][v] != 0 && (distance[v] > currDistance)) {
                distance[v] = currDistance;
                parent[v] = u;
            }
        }
        if(u == dest) {break;}
    }
    vector<int> v = printDijkstra(distance, parent, dest);
    return v;
}

vector<int> Graph::printDijkstra(int distance[], int parent[], int d) {
    vector<int> distanceVector;
    //for(int i = 0; i < V; i ++) {
        int pos = parent[d];
        cout<<d << " <- ";
        while(pos != -1) {
            cout<< pos << " <- ";
            pos = parent[pos];
        }
        cout << endl;
        cout<< "::::Distance = " << distance[d];
        cout<< "\n" << endl;
        distanceVector.push_back(distance[d]);
    //}
    cout << "\n" << endl;
    return distanceVector;
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

// void Graph::printCostMatrix() {
//     for(size_t i = 0; i < cost.size(); i++) {
//         for(size_t j = 0; j < cost[i].size(); j++) {
//             cout << cost[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << "\n" << endl;
// }