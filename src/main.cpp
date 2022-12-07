#include <iostream>
#include "Graph.h"
#include "Utils.h"

int main()
{   
    cout<< "Loading..."<< endl;
    cout<<"Welcome to Fantastic Roads!" << endl; //instructions for when we give user prompts
    /*  // Main Program: 
        //Creating Adjacency matrix: 
        // Need to construct empty matrix of size needed from data225.cpp, then create a graph using graph.cpp from it. May need to create setter method

        int vertices = 5;
        Graph g1(vertices);
        g1.addEdge(0, 1, 10); //node 1, node 2, edge weight
        g1.addEdge(0, 2, 3);
        g1.addEdge(1, 2, 1);
        g1.addEdge(2, 1, 4);
        g1.addEdge(2, 3, 8);
        g1.addEdge(1, 3, 2);
        g1.addEdge(2, 4, 2);
        g1.addEdge(3, 4, 7);
        g1.addEdge(4, 3, 9);

        bool flag = true;
        while(flag) {
            int src, dest, algorithm = -1, count;
            vector<int> dijkstraV;
            cout << "Please input your starting location: " << endl;
            cin >> src;
            cout << "Please input your desired destination: " << endl;
            cin >> dest;
            cout << endl;
            cout<< "Now time to choose your desired route-- your choices are: " << endl;
            cout << "   - Option 1: Passing through the fewest cities (recommended to avoid traffic to save time) -- enter 1 in console." << endl;
            cout << "   - Option 2: Shortest distance to location (recommended if gas economy is important) -- enter 2 in console." << endl;
            cout << "   - Option 3: Ranked roads (recommended if you really trust the computer and want the best of both worlds) -- enter 3 in console." << endl;
            cin >> algorithm;

            switch(algorithm) {
                case(1):
                    cout << "Route passing through fewest cities, step by step: " << endl;
                    g1.findShortestPathBFS(src, dest);
                    break;
                case(2):
                    dijkstraV = g1.dijkstra(src, dest);
                    cout << "Step by step list: ";
                    count = 1;
                    for(size_t i = 0; i < dijkstraV.size(); i++) {
                        cout << "Step " << count << ": " << dijkstraV[i] << endl;
                        count++;
                    }
                    break;
                case(3):
                    //Pagerank
                    break;
                default:
                    cout << "INVALID INPUT. Must be between 0 and 2." << endl;
                    break;
            }

            cout << "To terminate program, input 0 in console. To pick a new starting location and desired destination, input 1 in console." << endl;
            cin >> flag;
        }

        cout << "Finished running program 'Fantastic Roads'." << endl;
    */

    cout << "\n" << endl;
    
    cout << "\n" << endl;
    //Testing BFS
    cout<<"Testing BFS: " << endl;
    int vertices = 5;
    Graph g1(vertices);
    g1.addEdge(0, 1, 10); //node 1, node 2, edge weight
    g1.addEdge(0, 2, 3);
    g1.addEdge(1, 2, 1);
    g1.addEdge(2, 1, 4);
    g1.addEdge(2, 3, 8);
    g1.addEdge(1, 3, 2);
    g1.addEdge(2, 4, 2);
    g1.addEdge(3, 4, 7);
    g1.addEdge(4, 3, 9);
 
    int src, dest;
    cout<< "Please give a starting point: ";
    cin >> src;
    cout<< "Please give a destination: ";
    cin >> dest;
    cout << endl;
    g1.findShortestPathBFS(src, dest);


    cout << "\n" << endl;
    //Test for finding shortest path using Dijkstra's
    cout<<"Testing Dijkstra's: " << endl;
    // int src1, dest1;
    // cout<< "Please give a starting point: ";
    // cin >> src1;
    // cout<< "Please give a destination: ";
    // cin >> dest1;
    // cout << endl;
    
    vector<int> dijkstraVector; 
    cout<<"The path with the shortest distance starting at " << src << " and ending at " << dest << " is: " << endl;
    dijkstraVector = g1.dijkstra(src, dest);
   
    //Test for adjacency matrix
    cout << "Testing Adjacency Matrix: " << endl;
    g1.printAdjencyMatrix();
    

    return 0;
}