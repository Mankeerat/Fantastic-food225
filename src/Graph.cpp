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

vector<double> Graph::pageRank() {
    vector<double> pageRank;
    int rows = adjMatrix.size();
    int cols = adjMatrix[0].size();
    vector<double> ranks(rows, (double) 1 / rows);
    vector<vector<double>> sMatrix = stochastic(adjMatrix);
    vector<vector<double>> onesMatrix;
    for (int i = 0; i < rows; ++i) {
        vector<double> ones(cols, 1);
        onesMatrix.push_back(ones);
    }
    scaleMatrix(sMatrix, 0.85);
    scaleMatrix(onesMatrix, 0.15 / rows);
    addMatrices(sMatrix, onesMatrix);
    for (int i = 0; i < 100; ++i) {
        multiplyMatrices(ranks, sMatrix);
        // cout << "New Iteration: " << i << endl;
        // for (int i = 0; i < rows; ++i) {
        //     cout << ranks[i] << '\n';
        // }
    }
    // cout << "Ranks" << endl;
    // for (int i = 0; i < rows; ++i) {
    //     cout << ranks[i] << '\n';
    // }
    vector<pair<int, double>> sortVec;
    for (int i = 0; i < rows; ++i) {
        sortVec.push_back({i, ranks[i]});
    }
    sort(sortVec.begin(), sortVec.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
        return a.second > b.second;
    });
    for (int i = 0; i < rows; ++i) {
        pageRank.push_back(sortVec[i].first);
    }
    return pageRank; //cities sorted from highest rank to lowest rank (most busy to least busy)
}

vector<double> Graph::pageRank(int numIter, double damping) {
    vector<double> pageRank;
    int rows = adjMatrix.size();
    int cols = adjMatrix[0].size();
    vector<double> ranks(rows, (double) 1 / rows);
    vector<vector<double>> sMatrix = stochastic(adjMatrix);
    vector<vector<double>> onesMatrix;
    for (int i = 0; i < rows; ++i) {
        vector<double> ones(cols, 1);
        onesMatrix.push_back(ones);
    }
    scaleMatrix(sMatrix, damping);
    scaleMatrix(onesMatrix, (1 - damping) / rows);
    addMatrices(sMatrix, onesMatrix);
    for (int i = 0; i < numIter; ++i) {
        multiplyMatrices(ranks, sMatrix);
    }
    vector<pair<int, double>> sortVec;
    for (int i = 0; i < rows; ++i) {
        sortVec.push_back({i, ranks[i]});
    }
    sort(sortVec.begin(), sortVec.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
        return a.second > b.second;
    });
    for (int i = 0; i < rows; ++i) {
        pageRank.push_back(sortVec[i].first);
    }
    return pageRank;
}

vector<vector<double>> Graph::stochastic(const vector<vector<int>>& adjMatrix) {
    vector<vector<double>> sMatrix;
    int rows = adjMatrix.size();
    int cols = adjMatrix[0].size();
    for (int i = 0; i < rows; ++i) {
        vector<double> row(cols, 0);
        sMatrix.push_back(row);
    }
    for (int i = 0; i < cols; ++i) {
        int colSum = 0;
        for (int j = 0; j < rows; ++j) {
            colSum += adjMatrix[j][i];
        }
        for (int k = 0; k < rows; ++k) {
            sMatrix[k][i] = (double) adjMatrix[k][i] / colSum;
        }
    }
    return sMatrix;
}

void Graph::scaleMatrix(vector<vector<double>>& matrix, double scalar) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] *= scalar;
        }
    }
}

void Graph::addMatrices(vector<vector<double>>& matrix, const vector<vector<double>>& addMatrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] += addMatrix[i][j];
        }
    }
}

void Graph::multiplyMatrices(vector<double>& v, const vector<vector<double>>& multMatrix) {
    int rows = v.size();
    int cols = multMatrix[0].size();
    vector<double> resVector(rows, 0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            resVector[i] += (v[i] * multMatrix[i][j]);
        }
    }
    v = resVector;
}
