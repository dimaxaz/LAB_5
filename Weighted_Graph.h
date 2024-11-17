#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include "Abstract_Graph.h"

class Weighted_Graph : public Abstract_Graph {
private:
    int** adjacency_matrix; // ������� ��������� � ������
    int n; // ���������� ������
    int m; // ���������� �����

public:
    Weighted_Graph(int num_vertices, int num_edges);
    ~Weighted_Graph();
    void add_edge(int u, int v, int weight) override;
    void print_incidence_matrix() override;
    void determine_graph_size() override;
    void find_isolated_vertices() override;
    void find_terminal_vertices() override;
    void find_dominating_vertices() override;
};

#endif // WEIGHTED_GRAPH_H
