#include <iostream>

#include "Utils.h"
#include "Graph.h"

int tests() {
    
    // vector<string> list = {"chicago", "new_york", "madison", "evanston", "urbana", "nashville", "tampa", "miami", "dallas", "austin", "houston",
    //     "atlanta", "san_francisco", "los_angeles", "san_diego"
    // };  
    // map<int, string> cityMap;
    // int city_count = 0;

    // for(size_t num = 0; num < list.size(); num++) { //Constructs map with a city name associated with a number 0-length for mapping purposes 
    //     cityMap.insert({city_count, list.at(num)});
    //     city_count++;
    // }

    // for(auto itr = cityMap.begin(); itr != cityMap.end(); itr++) {  //prints cities mapped to their number
    //     cout<< "Number: " << itr->first << "   City: " << itr->second << endl;
    // }

    int v1 = 5;
    Graph g1(v1);
    g1.addEdge(0, 1, 1); //node 1, node 2, edge weight
    g1.addEdge(0, 2, 7);
    g1.addEdge(1, 2, 5);
    g1.addEdge(1, 4, 4);
    g1.addEdge(4, 3, 2); //currently not working for this node: why? 
    g1.addEdge(2, 3, 6);
    
    int src = 2, dest = 3;
    cout << "Testing BFS 1: "<<endl;
    cout<< "Should print:\n 1 3"<<endl;
    g1.findShortestPathBFS(src, dest);


    int v2 = 4;
    Graph g2(v2);
    g2.addEdge(0, 1, 2);
    g2.addEdge(0, 2, 2);
    g2.addEdge(1, 2, 1);
    g2.addEdge(1, 3, 1);
    g2.addEdge(2, 0, 1);
    g2.addEdge(2, 3, 2);
    g2.addEdge(3, 3, 2);
    
    int s = 1, d = 3;
    cout << "Testing BFS 2: "<<endl;
    cout<< "Should print:\n 3 2"<<endl;
    g2.findShortestPathBFS(s, d);
        


    // //Testing map of cities with distances 
    // cout << "Testing map of cities with distances: " << endl;   //<- possibly move this entire thing to a utils file if there are more functions like it 
    // map<string, int> newMap = mapDistanceGraph(dijkstraVector, cityMap);
    // printDistanceMap(newMap);


    //Tests for nearby cities to your location (given that distance is less than certain threshold) map<string, int> (vector<int> v, map<int, string> m)
    // cout <<"Printing Nearby Cities: " << endl;
    // double range = 1.0;
    // for(size_t d2 = 0; d2 < dijkstraVector.size(); d2++) {
    //     if(dijkstraVector[d2] <= range) {
    //         string str = "";
    //         str = cityMap.find(d2)->second;     
    //         cout << str << endl;
    //     }
    // }



    return 0;        
}
