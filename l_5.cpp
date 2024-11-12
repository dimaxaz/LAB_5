#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Graph {
private:
    int n;
    int** matrix;

public:
    Graph(int size) : n(size) {
        matrix = new int* [n];
        for (int i = 0; i < n; ++i) {
            matrix[i] = new int[n];
        }
        generate_adjacency_matrix();
    }

    ~Graph() {
        for (int i = 0; i < n; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void generate_adjacency_matrix() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = 0;
            }
        }

    // Заполняем матрицу случайными значениями
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (i != j) {
                    int edge = rand() % 2;
                    matrix[i][j] = edge;
                    matrix[j][i] = edge;
                }
            }
        }
    }

    void print_matrix() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    int get_graph_size() {
        return n;

        //кол-во ребер
        //int size = 0;
        //while (matrix[size] != nullptr) {
        //    size++;
        //}
        //return size;
    }
};

int main() {
    setlocale(LC_ALL, "");
    srand(time(0));

    int n = 10;
    Graph graph(n);

    graph.print_matrix();

    cout << "Размер графа (количество вершин): " << graph.get_graph_size() << endl;

    return 0;
}
