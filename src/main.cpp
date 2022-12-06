#include <iostream>
#include "Graph.h"
#include "Utils.h"

int main()
{   
    cout<< "Loading..."<< endl;
    cout<<"Welcome to Fantastic Roads! Please ..." << endl; //instructions for when we give user prompts
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
    int src1, dest1;
    cout<< "Please give a starting point: ";
    cin >> src1;
    cout<< "Please give a destination: ";
    cin >> dest1;
    cout << endl;
    
    vector<int> dijkstraVector; 
    cout<<"The path with the shortest distance starting at " << src1 << " and ending at " << dest1 << " is: " << endl;
    dijkstraVector = g1.dijkstra(src1, dest1);
   
    //Test for adjacency matrix
    cout << "Testing Adjacency Matrix: " << endl;
    g1.printAdjencyMatrix();
    

    return 0;
}