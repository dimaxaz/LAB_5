#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph(int num_vertices, int num_edges) : n(num_vertices), m(num_edges) {
    incidence_matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        incidence_matrix[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            incidence_matrix[i][j] = 0;
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < n; ++i) {
        delete[] incidence_matrix[i];
    }
    delete[] incidence_matrix;
}

void Graph::print_incidence_matrix() {
    cout << "Матрица инцидентности:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << incidence_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::determine_graph_size() {
    cout << "Количество вершин: " << n << endl;
    cout << "Количество ребер: " << m << endl;
}

void Graph::find_isolated_vertices() {
    cout << "Изолированные вершины: ";
    for (int i = 0; i < n; ++i) {
        bool isolated = true;
        for (int j = 0; j < m; ++j) {
            if (incidence_matrix[i][j] != 0) {
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

void Graph::find_terminal_vertices() {
    cout << "Концевые вершины: ";
    for (int i = 0; i < n; ++i) {
        int degree = 0;
        for (int j = 0; j < m; ++j) {
            if (incidence_matrix[i][j] != 0) {
                degree++;
            }
        }
        if (degree == 1) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void Graph::find_dominating_vertices() {
    cout << "Доминирующие вершины: ";
    for (int i = 0; i < n; ++i) {
        bool dominating = true;
        for (int j = 0; j < m; ++j) {
            if (incidence_matrix[i][j] == 0) {
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
