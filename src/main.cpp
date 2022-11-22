#include <iostream>
#include "Graph.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
    //Test for finding shortest path using BFS
    int V = 4;
    Graph g(V);
    g.addEdge(0, 1, 2); //node 1, node 2, cost
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 0, 1);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 3, 2);
 
    int src = 0, dest = 3;
    cout << "\nShortest Distance between " << src << " and " << dest << " is " << g.findShortestPathBFS(src, dest) << endl;

    //Test for finding shortest path using Dijkstra's
    // cout << "Enter n : "; 
    // cin >> V; 
    // cout << "Enter cost matrix : \n" ; 
    // for(int i = 0 ;i < V ; i++){
    //     for(int j = 0 ; j< V ; j++) { cin >> cost[i][j]; } 
    // }

    /*Need to figure out a way to calculate cost here-- right now it is just weighted edges*/    
    int src1; 
    cout<<"\nEnter source : " ;  cin >> src1 ;
    g.dijkstra(src1) ;     
 

    
    return 0;
}