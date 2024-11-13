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

    void set_matrix(int** mat) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = mat[i][j];
            }
        }
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

    void find_isolated_vertices() {
        cout << "Изолированные вершины: ";
        for (int i = 0; i < n; ++i) {
            bool isolated = true;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] != 0 || matrix[j][i] != 0) {
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

    void find_terminal_vertices() {
        cout << "Концевые вершины: ";
        for (int i = 0; i < n; ++i) {
            int degree = 0;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] != 0 || matrix[j][i] != 0) {
                    degree++;
                }
            }
            if (degree == 1) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    void find_dominating_vertices() {
        cout << "Доминирующие вершины: ";
        for (int i = 0; i < n; ++i) {
            bool dominating = true;
            for (int j = 0; j < n; ++j) {
                if (i != j && (matrix[i][j] == 0 && matrix[j][i] == 0)) {
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
};

    int main() {
        setlocale(LC_ALL, "");

        int n = 4;

        // Пример матрицы с изолированными вершинами
        int** isolated_matrix = new int* [n];
        for (int i = 0; i < n; ++i) {
            isolated_matrix[i] = new int[n];
            for (int j = 0; j < n; ++j) {
                isolated_matrix[i][j] = 0;
            }
        }

        // Пример матрицы с концевыми вершинами
        int** terminal_matrix = new int* [n];
        for (int i = 0; i < n; ++i) {
            terminal_matrix[i] = new int[n];
            for (int j = 0; j < n; ++j) {
                terminal_matrix[i][j] = 0;
            }
        }
        terminal_matrix[0][1] = 1;
        terminal_matrix[1][0] = 1;
        terminal_matrix[2][3] = 1;
        terminal_matrix[3][2] = 1;

        // Пример матрицы с доминирующей вершиной
        int** dominating_matrix = new int* [n];
        for (int i = 0; i < n; ++i) {
            dominating_matrix[i] = new int[n];
            for (int j = 0; j < n; ++j) {
                dominating_matrix[i][j] = 1;
            }
            dominating_matrix[i][i] = 0;
        }

        Graph isolated_graph(n);
        isolated_graph.set_matrix(isolated_matrix);
        isolated_graph.print_matrix();
        isolated_graph.find_isolated_vertices();

        Graph terminal_graph(n);
        terminal_graph.set_matrix(terminal_matrix);
        terminal_graph.print_matrix();
        terminal_graph.find_terminal_vertices();

        Graph dominating_graph(n);
        dominating_graph.set_matrix(dominating_matrix);
        dominating_graph.print_matrix();
        dominating_graph.find_dominating_vertices();

        // Освобождение памяти
        for (int i = 0; i < n; ++i) {
            delete[] isolated_matrix[i];
            delete[] terminal_matrix[i];
            delete[] dominating_matrix[i];
        }
        delete[] isolated_matrix;
        delete[] terminal_matrix;
        delete[] dominating_matrix;

        return 0;
    }