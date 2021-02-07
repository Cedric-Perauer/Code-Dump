#include <iostream>
#include "Graph.h"
#include "PriorityQueue.h"
#include "shortest_path.h"
#include <ctime>

using namespace std;
int main()
{//double dist_range[] = {1.0, 10.0};
    int num_vertices = 50;
    //double density;
    //cout << "Input density as double :" << endl;
    //cin >> density;
    //int monte_carlo_iteration = 1000;
    double avg_cost;
    long tStart = clock();
   // avg_cost = monte_carlo(monte_carlo_iteration, num_vertices, density, dist_range, 0, 2);
    //cout << "Average cost = " << avg_cost << endl;
    Graph *G = new Graph("G2.txt");
    //cout << G->V()<< endl;
    //cout << G->E() << endl;
    //print gaph matrix
    G->print_out();

    //Prim starts here
    G->doMST();
    //G->do_Max_Spanning_Tree();

    long tEnd = clock();
    cout << "\n";
    cout << "Execution time: " << tEnd-tStart << " ms" << endl;

    return 0;
}

