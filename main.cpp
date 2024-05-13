#include "graph.h"


using namespace::std;






int main() {


    Graph* graph = new Graph(7);
    
    // making above shown graph
    graph->add_edge(0, 1, 2);
    graph->add_edge(0, 2, 6);
    graph->add_edge(1, 3, 5);
    graph->add_edge(2, 3, 8);
    graph->add_edge(3, 4, 10);
    graph->add_edge(3, 5, 15);
    graph->add_edge(4, 6, 2);
    graph->add_edge(5, 6, 6);

    cout << "Shortest distance from 0 to 3 is " << graph->find_shortest(0, 3) << endl;

    


  
    
    return 0;
}