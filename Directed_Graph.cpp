#include "Directed_Graph.h"

void Directed_Graph::add_edge(int u, int v, int edge_index) {
    incidence_matrix[u][edge_index] = 1;
    incidence_matrix[v][edge_index] = -1; // Ориентированное ребро
}
