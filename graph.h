#include<iostream>
#include<vector>
#include<list>




class Graph {

    
    int V; //number of vertices
    std::list<std::pair<int,int> >* adj; // adjacency list

    public:
        Graph();

        Graph(int vertices);

        void add_edge(int u, int v, int w);

        int find_shortest(int src, int dest);

     

        ~Graph() {
            delete adj;

            std::cout << "Destructor is called" << std::endl;
        }



};

