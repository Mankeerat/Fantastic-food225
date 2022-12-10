#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include "Utils.h"
#include "Graph.h"

/**
 * Insert Test Cases for Dijkstras and BFS Here
 */

TEST_CASE("BFS", "[BFS]") {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 8);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 4, 5);
    g.addEdge(3, 4, 7);
    int result = 1;
    int shortestPath = g.findShortestPathBFS(2, 3);
    REQUIRE(shortestPath == result);
    Graph g2(10);
    g2.addEdge(0, 1, 4);
    g2.addEdge(0, 7, 8);
    g2.addEdge(1, 7, 11);
    g2.addEdge(7, 8, 7);
    g2.addEdge(7, 6, 1);
    g2.addEdge(1, 2, 8);
    g2.addEdge(2, 8, 2);
    g2.addEdge(8, 6, 6);
    g2.addEdge(6, 5, 2);
    g2.addEdge(2, 3, 7);
    g2.addEdge(2, 5, 4);
    g2.addEdge(3, 4, 9);
    g2.addEdge(3, 5, 14);
    g2.addEdge(5, 4, 10);
    g2.addEdge(4, 9, 3);
    result = 3;
    shortestPath = g2.findShortestPathBFS(1, 3);
    REQUIRE(shortestPath == result);
}

TEST_CASE("Dijkstra's", "[Dijkstra's]") {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 8);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 4, 5);
    g.addEdge(3, 4, 7);
    vector<int> result = {6};
    vector<int> dijkstraVector = g.dijkstra(2, 3);
    REQUIRE(dijkstraVector == result);
    Graph g2(10);
    g2.addEdge(0, 1, 4);
    g2.addEdge(0, 7, 8);
    g2.addEdge(1, 7, 11);
    g2.addEdge(7, 8, 7);
    g2.addEdge(7, 6, 1);
    g2.addEdge(1, 2, 8);
    g2.addEdge(2, 8, 2);
    g2.addEdge(8, 6, 6);
    g2.addEdge(6, 5, 2);
    g2.addEdge(2, 3, 7);
    g2.addEdge(2, 5, 4);
    g2.addEdge(3, 4, 9);
    g2.addEdge(3, 5, 14);
    g2.addEdge(5, 4, 10);
    g2.addEdge(4, 9, 3);
    result = {15};
    dijkstraVector = g2.dijkstra(1, 3);
    REQUIRE(dijkstraVector == result);
}

/**
 * Test cases for PageRank
 */

TEST_CASE("PageRank", "[PageRank]") {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 8);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 4, 5);
    g.addEdge(3, 4, 7);
    vector<int> result {2, 3, 1, 0, 4};
    vector<int> ranks = g.pageRank();
    REQUIRE(ranks == result);
    Graph g2(10);
    g2.addEdge(0, 1, 4);
    g2.addEdge(0, 7, 8);
    g2.addEdge(1, 7, 11);
    g2.addEdge(7, 8, 7);
    g2.addEdge(7, 6, 1);
    g2.addEdge(1, 2, 8);
    g2.addEdge(2, 8, 2);
    g2.addEdge(8, 6, 6);
    g2.addEdge(6, 5, 2);
    g2.addEdge(2, 3, 7);
    g2.addEdge(2, 5, 4);
    g2.addEdge(3, 4, 9);
    g2.addEdge(3, 5, 14);
    g2.addEdge(5, 4, 10);
    g2.addEdge(4, 9, 3);
    result = {7, 4, 5, 3, 1, 8, 2, 6, 0, 9};
    ranks = g2.pageRank();
    REQUIRE(ranks == result);
}

/**
 * Test cases for Matrix Operations
 */

TEST_CASE("Stochastic", "[PageRank]") {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 8);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 4, 5);
    g.addEdge(3, 4, 7);
    vector<vector<double>> sMatrix = g.stochastic(g.getAdjMatrix());
    vector<vector<double>> result {
        {0, 10.0 / 16.0, 3.0 / 20.0, 0, 0},
        {10.0 / 13.0, 0, 4.0 / 20.0, 2.0 / 17.0, 0},
        {3.0 / 13.0, 4.0 / 16.0, 0, 8.0 / 17.0, 5.0 / 12.0},
        {0, 2.0 / 16.0, 8.0 / 20.0, 0, 7.0 / 12.0},
        {0, 0, 5.0 / 20.0, 7.0 / 17.0, 0}
    };
    REQUIRE(sMatrix == result);
}

TEST_CASE("Scale Matrix", "[PageRank]") {
    double scalar = 0.85;
    vector<vector<double>> matrix {
        {4, 8},
        {3, 7}
    };
    vector<vector<double>> result {
        {3.4, 6.8},
        {2.55, 5.95}
    };
    scaleMatrix(matrix, scalar);
    REQUIRE(matrix == result);

    matrix = {
        {3, 4, 5},
        {6, 7, 8},
        {10, 11, 12}
    };
    result = {
        {2.55, 3.4, 4.25},
        {5.1, 5.95, 6.8},
        {8.5, 9.35, 10.2},
    };
    scaleMatrix(matrix, scalar);
    REQUIRE(matrix == result);
}

TEST_CASE("Add Matrices", "[PageRank]") {
    vector<vector<double>> matrix {
        {4, 8},
        {3, 7}
    };
    vector<vector<double>> addMatrix {
        {1, 0},
        {5, 2}
    };
    vector<vector<double>> result {
        {5, 8},
        {8, 9}
    };
    addMatrices(matrix, addMatrix);
    REQUIRE(matrix == result);
    
    matrix = {
        {3, 4, 5},
        {6, 7, 8},
        {10, 11, 12}
    };
    addMatrix = {
        {1, 2, 3},
        {4, 12, 1},
        {19, 9, 3},
    };
    result = {
        {4, 6, 8},
        {10, 19, 9},
        {29, 20, 15}
    };
    addMatrices(matrix, addMatrix);
    REQUIRE(matrix == result);
}

TEST_CASE("Multiply Matrices", "[PageRank]") {
    vector<double> v {0.5, 0.5};
    vector<vector<double>> multMatrix {
        {4, 8},
        {3, 7}
    };
    vector<double> result {6, 5};
    multiplyMatrices(v, multMatrix);
    REQUIRE(v == result);
}
