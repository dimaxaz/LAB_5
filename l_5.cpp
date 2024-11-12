#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generate_adjacency_matrix(int n, int matrix[][10]) {
    // Инициализируем матрицу смежности нулями
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

void print_matrix(int n, int matrix[][10]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    int n = 5; // Количество вершин в графе
    int matrix[10][10] = { 0 }; // Матрица смежности

    generate_adjacency_matrix(n, matrix);
    print_matrix(n, matrix);

    return 0;
}
