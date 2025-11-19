#include <iostream>
using namespace std;
int* maxOfThree(int* a, int* b, int* c) {
    if (*a >= *b && *a >= *c) {
        return a;
    } else if (*b >= *a && *b >= *c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    int x, y, z;
    cout << "Vvedite chisla: ";
    cin >> x >> y >> z;
    int* maxValue = maxOfThree(&x, &y, &z);
    double average = (x + y + z) / 3.0;
    *maxValue = static_cast<int>(average);
    cout << "Znacheniya: " << x << " " << y << " " << z <<endl;

    return 0;
}
