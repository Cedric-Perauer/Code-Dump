
#include <vector>
#include <map>
using namespace std;

#ifndef Graph_HEADER
#define Graph_HEADER
class Graph
{

private:
    double distance[2];
    vector <vector<double>> matrix_distance; //distance matrix
    int number_vertices; //number of vertices
    int number_edges;   //number of edges


public:
    map<int, double> node_value_map; //costs

    Graph();
    Graph(int number_vertices, double density, double distance[2]);
    //new mthod for reading in file
    Graph(char *file_name);
    void doMST();
    void print_out();
    int V(); //returns the number of vertices in the graph
    int E(); //returns the number of edges in the graph
    double get_node_value (int x); // returns the value associated with the node x.
    void set_node_value(int x, double a); // sets the value associated with the node x to a.
    double get_edge_value(int x, int y); //returns the value associated to the edge (x,y).
    void set_edge_value (int x, int y, double v); //sets the value associated to the edge (x,y) to v.
    bool check_for_element(vector<int> a, int x);  //used to check if node is already in closed set
    bool adjacent(int x, int y); //tests whether there is an edge from node x to node y.
    void do_Max_Spanning_Tree();
    vector<int> neighbors(int x); //lists all nodes y such that there is an edge from x to y.
    void add(int x, int y); //adds to G the edge from x to y, if it is not there.
    void remove(int x, int y); //removes the edge from x to y, if it is there.


};
#endif


