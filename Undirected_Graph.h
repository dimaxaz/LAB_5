#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H

#include "Graph.h"

class Undirected_Graph : public Graph {
public:
    Undirected_Graph(int num_vertices, int num_edges) : Graph(num_vertices, num_edges) {}
    void add_edge(int u, int v, int edge_index) override;
};

#endif // UNDIRECTED_GRAPH_H
