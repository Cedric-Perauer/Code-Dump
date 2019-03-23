#include <random>
#include <iostream>
#include <vector>
#include <ctime>
#include "Graph.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <iomanip>
#include <algorithm>
using namespace std;


void Graph::doMST() {
    vector<int> closed_set;
    vector<int> open_set;
    closed_set.push_back(0);

    //closed_set.push_back(1);


    //   for(const auto &j: closed_set) { //iterate over closed set with auto
    //      cout << j << endl;
    //  }
    int length_MST = 0;
    int a;
  while (closed_set.size() != V()) {
        //just pseudo code : while closed_set size != V() ....
        int minimum_distance = 10000; //set high minimum so one of the cost values will be smaller for sure


        for (const auto &j: closed_set) {
            //cout << *it << endl;
            for (int i = 0; i < V(); i++) {
                if ((get_edge_value(j, i) < minimum_distance) &&
                    (get_edge_value(j, i) != 0) && (check_for_element(closed_set,i) == false) ) { //pseudo && i not in closed_set
                    minimum_distance = get_edge_value(j, i);
                    // closed_set.push_back(i);
                    // cout << minimum_distance << endl;
                    //cout << i << endl;
                    a = i;
                }

              //  cout << i << endl;
            }

        }
        closed_set.push_back(a);
        length_MST += minimum_distance;
        cout << " adding number :" << a << endl;
        cout << "Minimum distance is : " << minimum_distance << endl;



    }

  //validate size and add path length for MST
 //   for( auto &j: closed_set) {
   //     cout << j << endl;


    //}
    //cout << " Size: " << closed_set.size() << endl;
    cout << "MST is : " << length_MST;
}

bool Graph::check_for_element(vector<int> a, int x) {
    if(find(a.begin(), a.end(), x) != a.end()) {
        return true;
    } else {
        return false;
    }
}

//function to print read in graph
void Graph:: print_out() {
    cout << "Node ";
    for (int i= 1; i < V(); i++) {
        cout << i << setw(5);
    }
    cout << '\n';

    for (int i= 0; i < V(); i++) {
        cout << i << setw(5);
        for (int j = 1; j < V(); j++) {
            cout << setw(5) << get_edge_value(j, i);
        }
        cout << endl;
    }

}

//calculate maximum spanning tree
void Graph::do_Max_Spanning_Tree()  {
    vector<int> closed_set;
    vector<int> open_set;
    closed_set.push_back(0);

    //closed_set.push_back(1);


    //   for(const auto &j: closed_set) { //iterate over closed set with auto
    //      cout << j << endl;
    //  }
    int length_MST = 0;
    int a;
    while (closed_set.size() != V()) {
        //just pseudo code : while closed_set size != V() ....
        int maximum_distance = -10; //set low value so maximum is higher


        for (const auto &j: closed_set) {
            //cout << *it << endl;
            for (int i = 0; i < V(); i++) {
                if ((get_edge_value(j, i) > maximum_distance) &&
                    (get_edge_value(j, i) != 0) && (check_for_element(closed_set,i) == false) ) { //pseudo && i not in closed_set
                    maximum_distance = get_edge_value(j, i);
                    // closed_set.push_back(i);
                    // cout << minimum_distance << endl;
                    //cout << i << endl;
                    a = i;
                }

                //  cout << i << endl;
            }

        }
        closed_set.push_back(a);
        length_MST += maximum_distance;
        cout << " adding number :" << a << endl;
        cout << "Maximum distance is : " << maximum_distance << endl;



    }

    //validate size and add path length for MST
    //   for( auto &j: closed_set) {
    //     cout << j << endl;


    //}
    //cout << " Size: " << closed_set.size() << endl;
    cout << "MST is : " << length_MST;
}






//new method for reading in file
Graph::Graph(char *file_name) {   //make sure to copy in the right directory

    ifstream myfile;
    string line;
    myfile.open(file_name);

    int a;
    //count number of lines = number_edges/2
    a = static_cast<int>(count(istreambuf_iterator<char>(myfile),
                               istreambuf_iterator<char>(), '\n'));
    this->number_edges = a / 2.0;  //number of edges divided by two as all of them are listed twice (bidirectional)
    myfile.close(); //close file


    //get number of verices
    myfile.open(file_name);
    if (myfile.is_open()) {
        getline(myfile, line);
        this->number_vertices = stoi(line);
    }
    myfile.close();

    //fill the vector with zeros
    for (int i = 0; i < number_vertices; i++){
        vector<double > zero_vector(number_vertices, 0);
        matrix_distance.push_back(zero_vector); }
    //get distances
    myfile.open(file_name);
    if (myfile.is_open()) {
        getline(myfile, line);

        int it = 0;
        while (myfile.good()) {   //myfile.good() makes sure to check for empty line
            getline(myfile, line);


            istringstream buf(line);
            istream_iterator<string> beg(buf), end;

            vector<string> tokens(beg, end); // done!
            int a[3];  //tracks the 3 values (node,node,distance)
            int i = 0;
            for (auto &s: tokens) {
                a[i] = stoi(s);
             //   cout << a[i] << '\t';
                i++;
            }
            set_edge_value(a[0],a[1], static_cast<float>(a[2])); //we could skip certain steps as we are iterating through everything twice
        //    set_edge_value(a[0]+1,a[1]+1, static_cast<float>(a[2]));
            //cout << '\n';

        }

    }
}







//get and set Methods
double Graph::get_node_value (int x){
    return node_value_map[x];
}

void Graph::set_node_value(int x, double a){
    node_value_map[x] = a;
}

//outputs zero if there is no conenction
double Graph::get_edge_value(int x, int y){
    return matrix_distance[x][y];
}

void Graph::set_edge_value(int x, int y, double v){
    matrix_distance[x][y] = v;
    matrix_distance[y][x] = v;
}


int Graph::V(){
    return number_vertices;
}

int Graph::E(){
    return number_edges;
}

bool Graph::adjacent(int x, int y){
    double current_d = get_edge_value(x, y);
    return current_d > 0.0;
}
vector<int> Graph::neighbors(int x){
    vector<int> neighbor;
    for (int i = 0; i < number_vertices; i++){
        if (adjacent(x, i)){
            neighbor.push_back(i);
        }
    }
    return neighbor;
}

void Graph::remove(int x, int y){
    if (adjacent(x, y)){
        matrix_distance[x][y] = 0;
        matrix_distance[y][x] = 0;
        number_edges -= 1;
    }
}


// default constructor
Graph::Graph(){
    this->number_vertices = 0;
    this->number_edges = 0;
}

// 2d vector constructor holds the distances between vertices
Graph::Graph(int num_vertices, double density, double dist_range[2]){
    this->number_vertices = num_vertices;
    this->number_edges = 0;
    this->distance[0] = dist_range[0];
    this->distance[1] = dist_range[1];
    mt19937 mt_rand(time(NULL));

    for (int i = 0; i < num_vertices; i++){
        vector<double > zero_vector(num_vertices, 0);
        matrix_distance.push_back(zero_vector);
        node_value_map[i] = 10 * num_vertices;
    }
    // init rand matrix
    for (int i = 0; i < num_vertices; i++){
        for (int j = i; j < num_vertices; j++){
            //  random distance
            uniform_real_distribution<double> random_density(0.0, 1.0);
            if ((j != i) && (random_density(mt_rand) < density &&! adjacent(i, j))){
                uniform_real_distribution<double> random_distance(dist_range[0], dist_range[1]);
                double d = random_distance(mt_rand);
                set_edge_value(i, j, d);
                number_edges += 1;
            }
            else {
                set_edge_value(i, j, 0.0); // else there is no edge
            }
        }
    }
}


