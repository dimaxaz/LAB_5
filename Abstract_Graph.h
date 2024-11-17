#ifndef ABSTRACT_GRAPH_H
#define ABSTRACT_GRAPH_H

class Abstract_Graph {
public:
    virtual ~Abstract_Graph() {}
    virtual void add_edge(int u, int v, int edge_index) = 0;
    virtual void print_incidence_matrix() = 0;
    virtual void determine_graph_size() = 0;
    virtual void find_isolated_vertices() = 0;
    virtual void find_terminal_vertices() = 0;
    virtual void find_dominating_vertices() = 0;
};

#endif // ABSTRACT_GRAPH_H
