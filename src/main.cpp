#include <iostream>
#include "Graph.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
    //Test for finding shortest path using BFS
    int vertices = 4;
    Graph g(vertices);
    g.addEdge(0, 1, 1); //node 1, node 2, edge weight
    g.addEdge(0, 2, 7);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 4, 4);
    g.addEdge(4, 3, 2); //currently not working for this node: why? 
    g.addEdge(2, 3, 6);
 
    int src = 0, dest = 3;
    cout << "\nShortest Distance between " << src << " and " << dest << " is " << g.findShortestPathBFS(src, dest) << endl;

    //Test for finding shortest path using Dijkstra's
    //cout << "\nUsing Dijkstra's algorithm, the shortest path between nodes is: "; 
    int src1; 
    cout<<"\nEnter source : " ;  cin >> src1 ;
    g.dijkstra(src1) ;     
 
    //Test for cost matrix
    cout << "Printing Cost Matrix: " << endl;
    g.printCost();
    

    /*For Dijkstra's need to show:
        - Neighboring cities: use Dijkstra's to map all distances into a map, and return cities in map with distance less than num
        - Shortest Distance: Should determine path that takes least amount of nodes (can be multiple)
        - Shortest Route: This will be accomplished using Pagerank too, but shortest route should determine the path with the least weight
    */ 
    

    return 0;
}