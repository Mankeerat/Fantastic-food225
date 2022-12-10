#include <iostream>
#include <chrono>
#include "Graph.h"
#include "Utils.h"

using namespace std::chrono;

int main() {   
    cout<< "Loading Data..."<< endl;
    // Creating Adjacency matrix: 
    // Need to construct empty matrix of size needed from data225.cpp, then create a graph using graph.cpp from it. May need to create setter method
    // int temp = data225(); commented out for efficiency --> need to change makefile and import data225.cpp into header

    // Getting total number of vertices from the matrix
    ifstream myFile("../tests/data/data_10k.txt");
    string line;
    int line_counter = 0;
    if(myFile.is_open()) {
        while(myFile.peek() != EOF) {
            getline(myFile, line);
            line_counter++;
        }
        myFile.close();
    }
    cout << "Number of Cities: " << line_counter << endl;
    int V = line_counter;   //setting our vertice count to our number of lines, and constructing a graph from that number
    Graph g(V);
    vector<vector<int>> matrixVector;   //creates matrix that will be copied into our graph
    matrixVector.resize(V, vector<int>(V));
        
    ifstream myFile2("../tests/data/data_10k.txt"); //parses matrix file that was generated in order to set the adjacency matrix in our graph
    if(myFile2.is_open()) {
        for(int u = 0; u < V; u++) {
            for(int v = 0; v < V; v++) {
                myFile2 >> matrixVector[u][v];
            }
        }
        myFile2.close();
    }

    g.setAdjMatrix(matrixVector);
    cout << "Data Loaded." << endl;

    bool flag = true;
    while(flag) {
        int src, dest, algorithm = -1, count;
        vector<int> dijkstraV;
        cout << "Welcome to Fantastic Roads!" << endl;
        cout << "Please input your starting location (0-990): " << endl;
        cin >> src;
        cout << "Please input your desired destination (0-990): " << endl;
        cin >> dest;
        cout << endl;
        cout<< "Now time to choose your desired route-- your choices are: " << endl;
        cout << "   - Option 1: Passing through the fewest cities (recommended to avoid traffic to save time) -- enter 1 in console." << endl;
        cout << "   - Option 2: Shortest distance to location (recommended if gas economy is important) -- enter 2 in console." << endl;
        cout << "   - Option 3: List of cities by popularity (recommended for route planning and selecting a good destination) -- enter 3 in console." << endl;
        cin >> algorithm;

        switch(algorithm) {
            case(1): {    //BFS
                cout << "Route passing through fewest cities, step by step: " << endl;
                auto start = high_resolution_clock::now();
                g.findShortestPathBFS(src, dest);
                cout << endl;
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<seconds>(stop -start);
                cout << "BFS takes " << duration.count() << " seconds to run." << endl;
                break;
            }
            case(2): {    //Dijkstra
                cout << "Shortest Distance to Location: " << endl;
                auto start = high_resolution_clock::now();
                dijkstraV = g.dijkstra(src, dest);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<seconds>(stop -start);
                cout << "Dijkstras takes " << duration.count() << " seconds to run." << endl;
                break;
            }
            case(3): {    //Pagerank
                cout << "List of Cities From Most Popular to Least Popular:" << endl;
                auto start = high_resolution_clock::now();
                g.pageRank(src, dest);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<seconds>(stop -start);
                cout << "PageRank takes " << duration.count() << " seconds to run." << endl;
                break;
            }
            default: {
                cout << "INVALID INPUT. Must be between 0 and 2." << endl;
                break;
            }
        }

        cout << "To pick a new starting location and desired destination, input 1 in console. To terminate program, input 0 in console. To" << endl;
        cin >> flag;
    }

    cout << "Finished running program 'Fantastic Roads'." << endl;
}
    