#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;

int get_from_interval(int a, int b) {
    return rand() % (b - a + 1) + a;
}

void echo_matrix(int**& matrix, int n) {
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

int**& fill_matrix(int n, int a, int b) {
    int*** matrix_ptr = new int**;
    *matrix_ptr = new int*[n];

    for(int i = 0; i < n; i++) {
        (*matrix_ptr)[i] = new int[n]; 

        for (int j = 0; j < n; j++) {
            (*matrix_ptr)[i][j] = get_from_interval(a, b);
        }
    }

    return *matrix_ptr;
}

void clear_matrix(int**& matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i]; 
    }

    delete[] matrix;

    matrix = nullptr; 
}

void draw_green(int**& matrix, int n) {
    int a = INT_MAX;
    int b = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i && j < n - 1 - i) {
                matrix[i][j] = a;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j > i & (i + j) > (n - 1)) {
                matrix[i][j] = b;
            }
        }
    }
}

int main() {
    srand(time(nullptr));

    int n, a, b; 
    cout << "Enter array size" << endl;
    cin >> n; 
    cout << "Enter interval for values generation" << endl; 
    cin >> a >> b; 

    int**& matrix = fill_matrix(n, a, b);

    draw_green(matrix, n); 

    echo_matrix(matrix, n); // Выводим матрицу на экран

    clear_matrix(matrix, n);

    return 0; 
}
