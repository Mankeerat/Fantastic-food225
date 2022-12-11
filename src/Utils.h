#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

map<string, int> mapDistanceGraph(vector<int> & v, map<int, string> & m);
void printDistanceMap(map<string, int> & m);
vector<int> nearbyCities(vector<int> v, float maxDistance);