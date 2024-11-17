#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include "Graph.h"

class Directed_Graph : public Graph {
public:
    Directed_Graph(int num_vertices, int num_edges) : Graph(num_vertices, num_edges) {}
    void add_edge(int u, int v, int edge_index) override;
};

#endif // DIRECTEDGRAPH_H
