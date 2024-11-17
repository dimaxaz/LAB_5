#ifndef GRAPH_H
#define GRAPH_H

#include "Abstract_Graph.h"

class Graph : public Abstract_Graph {
protected:
    int** incidence_matrix; // Матрица инцидентности
    int n; // Количество вершин
    int m; // Количество ребер

public:
    Graph(int num_vertices, int num_edges);
    virtual ~Graph();
    virtual void add_edge(int u, int v, int edge_index) override = 0;
    void print_incidence_matrix() override;
    void determine_graph_size() override;
    void find_isolated_vertices() override;
    void find_terminal_vertices() override;
    void find_dominating_vertices() override;
};

#endif // GRAPH_H
