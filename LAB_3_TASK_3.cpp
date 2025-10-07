#include <iostream>

using namespace std;

int sumchis(int n){
    int ostatok = 0;
    if (n > 9) {
        while (n > 0){
            ostatok += n%10;
            n /= 10;
        }
        return ostatok;
    }
    else {
        return n;
    }
}
int main()
{
    int maximum = 0;
    int minimum = INT_MAX;
    int casech;
    int new_num;
    while (true){
        cout << "Choose operation: \n 1. New number \n 2. Show max & min" << endl;
        cin >> casech;
        switch (casech){
        case 1:
            cout << "Enter number: ";
            cin >> new_num;
            if (sumchis(new_num) > maximum){
                maximum = sumchis(new_num);
            }
            if (sumchis(new_num) < minimum) {
                minimum = sumchis(new_num);

            }
            break;
        case 2:
            if (minimum > maximum) {
                minimum = 0;
            }
            cout << "Max sum = " << maximum << " min sum = " << minimum << endl;
            return 0;
        default:
            cout << "invalid input" << endl;
        }

    }
    return 0;
}
