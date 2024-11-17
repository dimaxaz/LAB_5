#include <iostream>
#include "Undirected_Graph.h"
#include "Directed_Graph.h"
#include "Weighted_Graph.h"

using namespace std;

void process_graph(Abstract_Graph& graph, const string& graph_type) {
    cout << "Processing " << graph_type << ":" << endl;
    graph.print_incidence_matrix();
    graph.determine_graph_size();
    graph.find_isolated_vertices();
    graph.find_terminal_vertices();
    graph.find_dominating_vertices();
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "");

    // Неориентированный граф
    Undirected_Graph undirected_graph(5, 4);
    undirected_graph.add_edge(0, 0, 0);
    undirected_graph.add_edge(0, 2, 1);
    undirected_graph.add_edge(2, 3, 2);
    undirected_graph.add_edge(3, 4, 3);
    process_graph(undirected_graph, "Undirected Graph");

    // Ориентированный граф
    Directed_Graph directed_graph(6, 5);
    directed_graph.add_edge(0, 1, 0);
    directed_graph.add_edge(1, 2, 1);
    directed_graph.add_edge(2, 3, 2);
    directed_graph.add_edge(3, 4, 3);
    directed_graph.add_edge(4, 5, 4);
    process_graph(directed_graph, "Directed Graph");

    // Взвешенный граф
    Weighted_Graph weighted_graph(4, 6); // 4 вершины, 6 ребер
    weighted_graph.add_edge(0, 1, 10);
    weighted_graph.add_edge(0, 2, 20);
    weighted_graph.add_edge(0, 3, 30);
    weighted_graph.add_edge(1, 2, 40);
    weighted_graph.add_edge(1, 3, 50);
    weighted_graph.add_edge(2, 3, 60);
    process_graph(weighted_graph, "Weighted Graph");

    return 0;
}
