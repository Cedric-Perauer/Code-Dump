//
// Created by ceddy on 3/12/2019.
//
#include "Graph.h"
#include "shortest_path.h"
#include "PriorityQueue.h"
#include "algorithm"
//Constructors
PriorityQueue::PriorityQueue(){
    make_heap(p_queue.begin(), p_queue.end(), greater<double>() );
}

PriorityQueue::PriorityQueue(vector<double> node_value){
    p_queue = node_value;
    make_heap(p_queue.begin(), p_queue.end(), greater<double>() );
}
// print the whole queue
void PriorityQueue::print(){
    for (auto i : p_queue){
        cout << i << endl;
    }
}
// does the queue contain queue_element.
bool PriorityQueue::contains(int queue_element){
    for (auto i : p_queue){
        if (i == queue_element){
            return true;
        }
    }
    return false;
}
// insert queue_element into queue.
void PriorityQueue::Insert(double queue_element){
    p_queue.push_back(queue_element);
    push_heap(p_queue.begin(), p_queue.end(), greater<double>() );
}
// changes the priority (node value) of queue element.
void PriorityQueue::chgPriority(double old_priority, double new_priority){
    if (contains(old_priority)){
        for (auto& i : p_queue){  //iterate through priority queue
            if (i == old_priority){
                i = new_priority;
                push_heap(p_queue.begin(), p_queue.end(), greater<double>() );
                return;
            }
        }
    }
}
// removes the top element of the queue.
void PriorityQueue::minPrioirty(){
    pop_heap(p_queue.begin(), p_queue.end(), greater<double>() );
    p_queue.pop_back();
    push_heap(p_queue.begin(), p_queue.end(), greater<double>() );
}
//returns the top element of the queue.
double PriorityQueue::top(){
    return p_queue.front();
}
// return the number of queue_elements.
int PriorityQueue::size(){
    return p_queue.size();
}


double monte_carlo(int num_iteration, int num_vertices, double density, double dist_range[2], int from_vertex, int to_vertex){
    double avg_cost = 0;
    for (int i = 0; i < num_iteration; i++){
        Graph G(num_vertices, density, dist_range);
        shortest_path shortest_path_dijkstra(G);
        double path_length = 0;
        double num_path = 0;
        for (int i = 0; i < num_vertices; i++){
            double per_path_cost = shortest_path_dijkstra.get_cost(from_vertex, i);
            if (per_path_cost > 0){ // when cost = 0, we know that there is no edge as described in Graph.cpp
                path_length += shortest_path_dijkstra.get_cost(from_vertex, i);
                num_path++;
            }
        }
        avg_cost += (path_length / num_path);
        cout << "iteration " << i << " with average path length = " << path_length / num_path << endl;

    }
    return avg_cost / double(num_iteration);
}