#include <iostream>
using namespace std;
int& max3(int& a, int& b, int& c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    int x, y, z;
    cout << "Vvedite chisla: ";
    cin >> x >> y >> z;

    int& maxomum = max3(x, y, z);
    double a = (x + y + z) / 3.0;

    maxomum = static_cast<int>(a);

    cout << "Znacheniya: " << x << " " << y << " " << z <<endl;

    return 0;
}
