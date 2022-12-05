#include <iostream>
#include <cache.h>

#include "Utils.h"
#include "Graph.h"

TEST_CASE("Testing BFS 1") {
    int vertices = 5;
    Graph g1(vertices);
    g1.addEdge(0, 1, 1); //node 1, node 2, edge weight
    g1.addEdge(0, 2, 7);
    g1.addEdge(1, 2, 5);
    g1.addEdge(1, 4, 4);
    g1.addEdge(4, 3, 2); //currently not working for this node: why? 
    g1.addEdge(2, 3, 6);
 
    int src = 2, dest = 3;
    
}

TEST_CASE("Testing BFS 2") {
    int v1 = 4;
    Graph g2(v1);
    g2.addEdge(0, 1, 2);
    g2.addEdge(0, 2, 2);
    g2.addEdge(1, 2, 1);
    g2.addEdge(1, 3, 1);
    g2.addEdge(2, 0, 1);
    g2.addEdge(2, 3, 2);
    g2.addEdge(3, 3, 2);
 
    int s = 1, d = 3;

    REQUIRE(g2.findShortestPathBFS(s, d) == "3, 2");
}