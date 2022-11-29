#include <iostream>
#include "Graph.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{   
    cout<< "Loading..."<< endl;
    cout<<"Welcome to Fantastic Roads! Please ..." << endl; //instructions for when we give user prompts
    cout << "\n" << endl;


    vector<string> list = {"chicago", "new_york", "madison", "evanston", "urbana", "nashville", "tampa", "miami", "dallas", "austin", "houston",
        "atlanta", "san_francisco", "los_angeles", "san_diego"
    };  
    map<int, string> cityMap;
    int city_count = 0;

    for(size_t num = 0; num < list.size(); num++) { //Constructs map with a city name associated with a number 0-length for mapping purposes 
        cityMap.insert({city_count, list.at(num)});
        city_count++;
    }

    for(auto itr = cityMap.begin(); itr != cityMap.end(); itr++) {
        cout<< "Number: " << itr->first << "   City: " << itr->second << endl;
    }
    //Will need a way (will not be difficult) to return a vector of nodes from print methods in order to find in the map and print the correct city associated with the number
    
    cout << "\n" << endl;
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
    
    cout << "Graph 1: "<< endl;
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
 
    int s = 3, d = 3;
    cout << "Graph 2: "<< endl;
    cout << "\nShortest Distance between " << s << " and " << d << " is " << g2.findShortestPathBFS(s, d);

    cout << "\n" << endl;


    //Test for finding shortest path using Dijkstra's
    cout<<"Testing Dijkstra's: " << endl;
    int src1; 
    cout<<"\nEnter source: " ;  cin >> src1 ;
    vector<int> dijkstraVector;
    dijkstraVector = g1.dijkstra(src1);


    //Prints distance vector 
    cout << "Testing Dijkstra's Distance Vector: "<< endl;
    for(size_t d = 0; d < dijkstraVector.size(); d++) {
            cout << dijkstraVector[d] << endl;
    }  


    cout << "\n" << endl;
    //Testing map of cities with distances 
    cout << "Testing map of cities with distances: " << endl;   //<- possibly move this entire thing to a utils file if there are more functions like it 
    map<string, int> newMap = mapDistanceGraph(dijkstraVector, cityMap);
    printDistanceMap(newMap);


    //Tests for nearby cities to your location (given that distance is less than certain threshold) map<string, int> (vector<int> v, map<int, string> m)
    cout <<"Printing Nearby Cities: " << endl;
    double range = 1.0;
    for(size_t d2 = 0; d2 < dijkstraVector.size(); d2++) {
        if(dijkstraVector[d2] <= range) {
            string str = "";
            str = cityMap.find(d2)->second;     
            cout << str << endl;
        }
    }


    cout << "\n" << endl;
    //Test for cost matrix
    cout << "Testing Cost Matrix: " << endl;
    g1.printCostMatrix();
    

    return 0;
}