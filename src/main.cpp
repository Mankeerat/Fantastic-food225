#include <iostream>
#include "Graph.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
    vector<string> list = {"chicago", "new_york", "madison", "evanston", "urbana", "nashville", "tampa", "miami", "dallas", "austin", "houston",
        "atlanta", "san_francisco", "los_angeles", "san_diego"
    };
    map<int, string> cityMap;
    int city_count = 0;

    for(size_t num = 0; num < list.size(); num++) {
        cityMap.insert({city_count, list.at(num)});
        city_count++;
    }

    for(auto itr = cityMap.begin(); itr != cityMap.end(); itr++) {
        cout<< "Number: " << itr->first << "   City: " << itr->second << endl;
    }
    //Will need a way (will not be difficult) to return a vector of nodes from print methods in order to find in the map and print the correct city associated with the number
    
    //Testing BFS
    cout<<"Testing BFS: " << endl;
    int vertices = 5;
    Graph g1(vertices);
    g1.addEdge(0, 1, 1); //node 1, node 2, edge weight
    g1.addEdge(0, 2, 7);
    g1.addEdge(1, 2, 5);
    g1.addEdge(1, 4, 4);
    g1.addEdge(4, 3, 2); //currently not working for this node: why? 
    g1.addEdge(2, 3, 6);
 
    int src = 2, dest = 3;
    
    cout << "\nShortest Distance between " << src << " and " << dest << " is " << g1.findShortestPathBFS(src, dest) << endl;

       int v1 = 4;
        Graph g2(v1);
        g2.addEdge(0, 1, 2);
        g2.addEdge(0, 2, 2);
        g2.addEdge(1, 2, 1);
        g2.addEdge(1, 3, 1);
        g2.addEdge(2, 0, 1);
        g2.addEdge(2, 3, 2);
        g2.addEdge(3, 3, 2);
 
    int s = 0, d = 3;
    cout << "\nShortest Distance between " << s
        << " and " << d << " is "
        << g2.findShortestPathBFS(s, d);

    cout << "\n" << endl;
    //Test for finding shortest path using Dijkstra's
    cout<<"Testing Dijkstra's: " << endl;
    int src1; 
    cout<<"\nEnter source: " ;  cin >> src1 ;
    vector<int> dijkstraVector;
    dijkstraVector = g1.dijkstra(src1);

    //Tests for nearby cities to your location (given that distance is less than certain threshold)
    for(size_t d = 0; d < dijkstraVector.size(); d++) {
        cout << dijkstraVector[d] << endl;
        if(dijkstraVector[d] <= 1) {
            string str = "";
            str = cityMap.find(dijkstraVector[d])->second;  
            cout << str << endl;
        }
    }     

    //Tests for shortest path based on shortest nodes that you will pass through 


    //Test for cost matrix
    cout << "Testing Cost Matrix: " << endl;
    g1.printCost();
    

    /*For Dijkstra's need to show:
        - Neighboring cities: use Dijkstra's to map all distances into a map, and return cities in map with distance less than num
        - Shortest Distance: Should determine path that takes least amount of nodes (can be multiple)
        - Shortest Route: This will be accomplished using Pagerank too, but shortest route should determine the path with the least weight
    */ 
    

    return 0;
}