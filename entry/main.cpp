#include <iostream>
#include "Graph.h"
#include "Utils.h"

int main() {   
    cout<< "Loading..."<< endl;
    cout<<"Welcome to Fantastic Roads!" << endl; //instructions for when we give user prompts
    /*  // Main Program (comment out if running tests): 
        //Creating Adjacency matrix: 
        // Need to construct empty matrix of size needed from data225.cpp, then create a graph using graph.cpp from it. May need to create setter method
        //int temp = data225(); commented out for efficiency --> need to change makefile and import data225.cpp into header

        //Getting total number of vertices from the matrix
        ifstream myFile("matrix_10k.txt");
        string line;
        int line_counter = 0;
        if(myFile.is_open()) {
            while(myFile.peek() != EOF) {
                getline(myFile, line);
                line_counter++;
                //cout << line_counter << endl;
            }
            myFile.close();
        }
        //cout << line_counter << endl;
        int V = line_counter;   //setting our vertice count to our number of lines, and constructing a graph from that number
        Graph g(V);
        vector<vector<int>> matrixVector;   //creates matrix that will be copied into our graph
        matrixVector.resize(V, vector<int>(V));
        
        int u, v;
        int w; // getting edges from user
        g.setMatrix(matrixVector);

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
            int src = 1, dest=5, algorithm = -1, count;
            vector<int> dijkstraV;
            cout << "Welcome to Fantastic Roads!" << endl;
            cout << "Please input your starting location: " << endl;
            //cin >> src;
            cout << "Please input your desired destination: " << endl;
            //cin >> dest;
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
    // */


    /*TESTS BELOW (comment if running main code, uncomment if you would like to run tests)*/

    //GRAPH 1
    // int vertices = 5;
    // Graph g1(vertices);
    // g1.addEdge(0, 1, 10); //node 1, node 2, edge weight
    // g1.addEdge(0, 2, 3);
    // g1.addEdge(1, 2, 4);
    // g1.addEdge(2, 3, 8);
    // g1.addEdge(1, 3, 2);
    // g1.addEdge(2, 4, 5);
    // g1.addEdge(3, 4, 7);

    // //GRAPH 2
    // int vertices2 = 10;
    // Graph g2(vertices2);
    // g2.addEdge(0, 1, 4);
    // g2.addEdge(0, 7, 8);
    // g2.addEdge(1, 7, 11);
    // g2.addEdge(7, 8, 7);
    // g2.addEdge(7, 6, 1);
    // g2.addEdge(1, 2, 8);
    // g2.addEdge(2, 8, 2);
    // g2.addEdge(8, 6, 6);
    // g2.addEdge(6, 5, 2);
    // g2.addEdge(2, 3, 7);
    // g2.addEdge(2, 5, 4);
    // g2.addEdge(3, 4, 9);
    // g2.addEdge(3, 5, 14);
    // g2.addEdge(5, 4, 10);
    // g2.addEdge(4, 9, 3);


    // int src, dest;
    // cout<< "Please give a starting point: ";
    // cin >> src;
    // cout<< "Please give a destination: ";
    // cin >> dest;
    

    // cout << "\n" << endl;
    // //Testing BFS
    // cout<<"Testing BFS: " << endl;
    // cout << endl;
    // g1.findShortestPathBFS(src, dest);  //change g1 to g2 if testing graph 2

    // //Uncomment below to test BFS for every node in the graph (do NOT do this for the full dataset)
    // // for(int i = 0; i < vertices; i++) {    //change to vertices2 for for loops if testing graph 2
    // //     src = i;
    // //     for(int j = 0; j < vertices;j++) {
    // //         dest = j;
    // //         g1.findShortestPathBFS(src, dest);
    // //         cout<< " ";
    // //     }
    // //     cout << endl;
    // // }
    
   

    // cout << "\n" << endl;
    // //Test for finding shortest path using Dijkstra's
    // cout<<"Testing Dijkstra's: " << endl;
    // vector<int> dijkstraVector;
    // cout<<"The path with the shortest distance starting at " << src << " and ending at " << dest << " is: " << endl;
    // dijkstraVector = g1.dijkstra(src, dest);    //change g1 to g2 if testing graph 2
    
    // //Uncomment below to test Dijkstra's for every node in the graph (do NOT do this for the full dataset)
    // // for(int i = 0; i < vertices; i++) {    //change to vertices2 for for loops if testing graph 2
    // //     src = i;
    // //     for(int j = 0; j < vertices;j++) {
    // //         dest = j; 
    // //         cout<<"The path with the shortest distance starting at " << src << " and ending at " << dest << " is: " << endl;
    // //         dijkstraVector = g1.dijkstra(src, dest);  //change to g2 if testing graph 2
    // //         cout<< " ";
    // //     }
    // //     cout << endl;
    // // }
   
   
    // //Test for adjacency matrix (comment out if you are using the full dataset)
    // cout << "Testing Adjacency Matrix: " << endl;
    // g1.printAdjencyMatrix();

    // cout << "Testing PageRank:" << endl;
    // g1.pageRank();
    // g1.pageRank(100, 0.85);

    return 0;
}