#include "graph.h"
#include <queue>

using namespace::std;

void Graph::add_edge(int u, int v, int w) {

    adj[u].push_back(std::make_pair(v, w));
    adj[v].push_back(std::make_pair(u, w));

}


Graph::Graph() {

    V = 0;
    adj = nullptr;
}

Graph::Graph(int vertices) {
    
    V = vertices;
    adj = new list<pair<int, int> >[vertices];

}

// Implementing dijkstra's algorithm
// We have a priority queue




// In this function, we find the shortest path from the source vector to all the other sources
int Graph::find_shortest(int source, int dest) {

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    // Have a vector of visited vertices


    // Each index will have the same value as it's index
    vector<int> visited_vertices(V, INFINITY);


    // Assign the distance to the source as zero
    visited_vertices[source] = 0;




    // distance is first index in tuple because tuple compares only check the first elements
    pq.push(make_pair(0, source));

    while(!pq.empty()) {


        pair<int,int> shortest = pq.top();

        pq.pop();

        // find the vertex with the shortest distance
        int vert_index = shortest.second;
        int vert_weight = shortest.first;

        list<pair<int, int> >::iterator i;

        // Loop through the adjacent vertices
        // cout << "Current vertext is " << vert_index << endl;
        for (i = adj[vert_index].begin(); i != adj[vert_index].end(); i++) {
            
            pair<int, int> curr_elem = (*i);

            int curr_vertex = curr_elem.first;
            int curr_weight = curr_elem.second;

            // cout << "Adjacent vertex is " << curr_vertex << endl;

            if(visited_vertices[curr_vertex] > visited_vertices[vert_index] + curr_weight) {
                visited_vertices[curr_vertex] = visited_vertices[vert_index] + curr_weight;
                pq.push(make_pair(visited_vertices[curr_vertex], curr_vertex));
            }
        }

    }

    // for(int j = 0; j < V; j++) {

    //     cout << "Distance from vertex " << source << " to vertex " << j << " is " << visited_vertices[j] << endl;
    // }

    return visited_vertices[dest];
}


