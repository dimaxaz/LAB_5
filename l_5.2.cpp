#include <iostream>

using namespace std;

class Graph {
private:
    int n;
    int m;
    int** incidence_matrix;
    int** edges;

public:
    Graph(int size) : n(size), m(0) {
        edges = new int* [n * n];
        incidence_matrix = new int* [n];
        for (int i = 0; i < n; ++i) {
            incidence_matrix[i] = new int[n * n];
            for (int j = 0; j < n * n; ++j) {
                incidence_matrix[i][j] = 0;
            }
        }
    }

    ~Graph() {
        for (int i = 0; i < n; ++i) {
            delete[] incidence_matrix[i];
        }
        delete[] incidence_matrix;
        for (int i = 0; i < m; ++i) {
            delete[] edges[i];
        }
        delete[] edges;
    }

    void add_edge(int u, int v) {
        edges[m] = new int[2];
        edges[m][0] = u;
        edges[m][1] = v;
        m++;
    }

    void build_incidence_matrix() {
        for (int j = 0; j < m; ++j) {
            int u = edges[j][0];
            int v = edges[j][1];
            incidence_matrix[u][j] = 1;
            incidence_matrix[v][j] = 1;
        }
    }

    void print_incidence_matrix() {
        cout << "Матрица инцидентности:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << incidence_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void determine_graph_size() {
        int num_vertices = n;
        int num_edges = m;
        cout << "Количество вершин: " << num_vertices << endl;
        cout << "Количество ребер: " << num_edges << endl;
    }
};

int main() {
    setlocale(LC_ALL, "");

    int n = 4;
    Graph graph(n);

    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 0);

    graph.build_incidence_matrix();

    graph.print_incidence_matrix();

    graph.determine_graph_size();

    return 0;
}
