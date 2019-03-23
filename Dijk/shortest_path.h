#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"
#include "PriorityQueue.h"
using namespace std;

class shortest_path{
private:
    Graph G;

public:
    vector<vector<int> > path_matrix;
    shortest_path();
    shortest_path(Graph G);
    map<int, double> shortest_dist_from_vertex(int vertex); // returns a vector of min distances from i to every other vertex j
    vector<double> closest_vertex(map<int, double> sptMap); // returns a vector of minimum {vertex, distance} from current sptSet
    double get_cost(int from_vertex, int to_vertex);
    string get_path(int from_vertex, int to_vertex);
};

//executed in main

