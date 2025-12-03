#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;

// Функция для получения случайного числа в интервале [a, b]
int get_from_interval(int a, int b) {
    return rand() % (b - a + 1) + a; // Генерируем случайное число
}

// Функция для вывода матрицы на экран
void echo_matrix(int**& matrix, int n) {
    for (int i = 0; i < n; i++) { // Проходим по строкам матрицы
        for (int j = 0; j < n; j++) { // Проходим по столбцам матрицы
            cout << matrix[i][j] << ' '; // Выводим элемент матрицы
        }
        cout << endl;
    }
}

// Функция для заполнения матрицы случайными числами в заданном интервале
int**& fill_matrix(int n, int a, int b) {
    int*** matrix_ptr = new int**; // Создаем указатель на указатель на указатель (для динамической матрицы)
    *matrix_ptr = new int*[n]; // Выделяем память для массива указателей на строки

    for(int i = 0; i < n; i++) { // Проходим по строкам матрицы
        (*matrix_ptr)[i] = new int[n]; // Выделяем память для каждой строки матрицы

        for (int j = 0; j < n; j++) { // Проходим по столбцам матрицы
            (*matrix_ptr)[i][j] = get_from_interval(a, b); // Заполняем элемент случайным числом
        }
    }

    return *matrix_ptr; // Возвращаем указатель на матрицу
}

// Функция для освобождения памяти, занятой матрицей
void clear_matrix(int**& matrix, int n) {
    for (int i = 0; i < n; i++) { // Проходим по строкам матрицы
        delete[] matrix[i]; // Освобождаем память, занятую каждой строкой
    }

    delete[] matrix; // Освобождаем память, занятую массивом указателей на строки

    matrix = nullptr; // Устанавливаем указатель в nullptr для предотвращения утечек памяти
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

// Обнуляет верхний правый треугольник (аналог красной зоны на картинке)

// Основная функция программы
int main() {
    srand(time(nullptr)); // Инициализируем генератор случайных чисел текущим временем

    int n, a, b; // Объявляем переменные для размера матрицы и границ интервала
    cout << "Enter array size" << endl; // Запрашиваем размер матрицы у пользователя
    cin >> n; // Считываем размер матрицы
    cout << "Enter interval for values generation" << endl; // Запрашиваем границы интервала
    cin >> a >> b; // Считываем границы интервала

    int**& matrix = fill_matrix(n, a, b); // Заполняем матрицу случайными числами

    draw_green(matrix, n); // Модифицируем матрицу, обнуляя определенные элементы

    echo_matrix(matrix, n); // Выводим матрицу на экран

    clear_matrix(matrix, n); // Освобождаем память, занятую матрицей

    return 0; // Завершаем программу
}
