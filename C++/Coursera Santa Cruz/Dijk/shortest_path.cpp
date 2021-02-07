//
// Created by ceddy on 3/12/2019.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "shortest_path.h"
#include "Graph.h"
#include "PriorityQueue.h"


using namespace std;

shortest_path::shortest_path(){}

shortest_path::shortest_path(Graph G){
    this->G = G;
    int num_vertices = G.V();
    for (int i = 0; i < num_vertices; i++){
        vector<int > zero_vector(num_vertices, 10000000); // 10000000 represents there is no path from i to j.
        path_matrix.push_back(zero_vector);
    }
    for (int i = 0; i < num_vertices; i++){
        map<int, double> test = shortest_dist_from_vertex(i);
    }
}

map<int, double> shortest_path::shortest_dist_from_vertex(int vertex){
    map<int, double> sptMap;
    vector<int> sptSet{vertex};
    sptMap[vertex] = 0;
    vector<int> neighbors = G.neighbors(vertex);
    if (neighbors.empty()){
        return sptMap;
    }
    PriorityQueue current_distance;
    map<double, vector<int> > current_dist_vertex_pair;
    for (auto i : neighbors){
        double d = G.get_edge_value(vertex, i);
        current_distance.Insert(d);
        current_dist_vertex_pair[d].push_back(i);
    }
    // register min distance to sptMap
    double min_d = current_distance.top();
    sptMap[current_dist_vertex_pair[min_d][0]] = min_d;
    path_matrix[vertex][current_dist_vertex_pair[min_d][0]] = vertex;
    // loop over the remaining vertices
    vector<double> new_shortest = closest_vertex(sptMap);
    while (new_shortest[1] < 1000000){
        int new_vertex = int(new_shortest[0]);
        int from_vertex = int(new_shortest[2]);
        path_matrix[vertex][new_vertex] = from_vertex;
        sptMap[new_vertex] = new_shortest[1];
        new_shortest = closest_vertex(sptMap);
    }

    return sptMap;
}

vector<double> shortest_path::closest_vertex(map<int, double> sptMap){
    vector<double> closest{0, 1000000, 0}; // stores {closest_vertex, distance, from_vertex}
    vector<int> sptSet; // vertices already stored in closest path set
    for (auto& pair : sptMap){
        sptSet.push_back(pair.first);
    }

    for (auto vertex : sptSet){
        double d_to_vertex = sptMap[vertex]; // shortest distance to vertex
        vector<int> neighbors = G.neighbors(vertex);
        PriorityQueue current_distance;
        map<double, vector<int> > current_dist_vertex_pair;
        if ( neighbors.empty()==false){
            for (auto i : neighbors){ // for each neighbor, we collect distance and vertex if not existed in sptSet
                if (find(sptSet.begin(), sptSet.end(), i) == sptSet.end()) {
                    // vertices that have not been added to shortest distance
                    double d = G.get_edge_value(vertex, i);
                    current_distance.Insert(d); // insert distance to a priority queue
                    current_dist_vertex_pair[d].push_back(i);
                }
            }
            if (current_distance.size() > 0){ // check if there's any new vertices to be added
                double min_d = current_distance.top();
                if (min_d + d_to_vertex < closest[1]){ // update closest according to min distance from each vertex
                    closest[0] = current_dist_vertex_pair[min_d][0]; // select the first vertex if multiple vertices have the same distance
                    closest[1] = min_d + d_to_vertex;
                    closest[2] = vertex;
                }
            }
        }
    }
    return closest;
}

double shortest_path::get_cost(int from_vertex, int to_vertex){
    int connection = path_matrix[from_vertex][to_vertex];
    if (connection == 10000000){ // that means no edge so cost is set to 0
        return 0;
    }
    double cost = 0;
    while (connection != from_vertex){
        cost += G.get_edge_value(connection, to_vertex);
        to_vertex = connection;
        connection = path_matrix[from_vertex][to_vertex];
    }
    cost += G.get_edge_value(connection, to_vertex);
    return cost;
}


string shortest_path::get_path(int from_vertex, int to_vertex){
    int connection = path_matrix[from_vertex][to_vertex];
    if (connection == 10000000){
        return "no path";
    }
    string path = to_string(to_vertex);
    while (connection != from_vertex){
        path = to_string(connection) + "-" + path;
        to_vertex = connection;
        connection = path_matrix[from_vertex][to_vertex];
    }
    path = to_string(connection) + "-" + path;
    return path;
}


