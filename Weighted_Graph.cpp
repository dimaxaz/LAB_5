#include "Weighted_Graph.h"
#include <iostream>

using namespace std;

Weighted_Graph::Weighted_Graph(int num_vertices, int num_edges) : n(num_vertices), m(num_edges) {
    adjacency_matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        adjacency_matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            adjacency_matrix[i][j] = 0;
        }
    }
}

Weighted_Graph::~Weighted_Graph() {
    for (int i = 0; i < n; ++i) {
        delete[] adjacency_matrix[i];
    }
    delete[] adjacency_matrix;
}

void Weighted_Graph::add_edge(int u, int v, int weight) {
    adjacency_matrix[u][v] = weight;
    adjacency_matrix[v][u] = weight; // Для неориентированного графа
}

void Weighted_Graph::print_incidence_matrix() {
    cout << "Матрица смежности (взвешенный граф):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << adjacency_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Weighted_Graph::determine_graph_size() {
    cout << "Количество вершин: " << n << endl;
    cout << "Количество ребер: " << m << endl;
}

void Weighted_Graph::find_isolated_vertices() {
    cout << "Изолированные вершины: ";
    for (int i = 0; i < n; ++i) {
        bool isolated = true;
        for (int j = 0; j < n; ++j) {
            if (adjacency_matrix[i][j] != 0) {
                isolated = false;
                break;
            }
        }
        if (isolated) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void Weighted_Graph::find_terminal_vertices() {
    cout << "Концевые вершины: ";
    for (int i = 0; i < n; ++i) {
        int degree = 0;
        for (int j = 0; j < n; ++j) {
            if (adjacency_matrix[i][j] != 0) {
                degree++;
            }
        }
        if (degree == 1) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void Weighted_Graph::find_dominating_vertices() {
    cout << "Доминирующие вершины: ";
    for (int i = 0; i < n; ++i) {
        bool dominating = true;
        for (int j = 0; j < n; ++j) {
            if (i != j && adjacency_matrix[i][j] == 0) {
                dominating = false;
                break;
            }
        }
        if (dominating) {
            cout << i << " ";
        }
    }
    cout << endl;
}
