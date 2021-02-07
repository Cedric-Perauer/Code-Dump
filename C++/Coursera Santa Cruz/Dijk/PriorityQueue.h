//
// Created by ceddy on 3/12/2019.
//

#ifndef GRAPH_PRIORITYQUEUE_H
#define GRAPH_PRIORITYQUEUE_H

#include "Graph.h"

class PriorityQueue {
private:
    vector<double> p_queue;

public:
    PriorityQueue(); //Constructors
    PriorityQueue(vector<double> p_queue);
    void chgPriority(double old_priority, double new_priority); // changes the priority (node value) of queue element.
    void minPrioirty(); // removes the top element of the queue.
    bool contains(int queue_element); // does the queue contain queue_element.
    void Insert(double queue_element); // insert queue_element into queue.
    double top(); //returns the top element of the queue.
    int size(); // return the number of queue_elements.
    void print(); // print the queue
};

double monte_carlo(int num_iteration, int num_vertices, double density, double dist_range[2], int from_vertex, int to_vertex);

#endif //GRAPH_PRIORITYQUEUE_H
