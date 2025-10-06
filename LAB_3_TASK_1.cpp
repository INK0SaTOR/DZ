#include <iostream>
#include <cmath>
using namespace std;

int simple(int n) {
	if (n == 1  || n == 0) return 0;
	if (n == 2 || n == 3) return n;
	if (n % 2 == 0 || n % 3 == 0) return 0;
	if (n % n == 0 && n % 1 == 0) return n;
}

void MAXIMKA (int a, int b){
    for (int i = a; i <= b-2; i ++ ){
        if (simple(i) && simple(i+2)){
            cout << i << ", " << i + 2 << endl;
        }
    }
}

int main () {
    int a, b;
    cin >> a >> b;
    cout << "every simple num: "<< endl;
    for (int i = a; i <=b; i++ ){
        if (simple (i)) {
            cout << i << endl;
        }
    }
    cout << endl;
    cout << "friendly nums: " << endl;
    MAXIMKA(a, b);

}
