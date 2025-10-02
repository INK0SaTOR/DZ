#include <iostream>
#include <cmath>
using namespace std;

int ploshad_krug(int r){
    double S = M_PI * pow(r, 2);
    return S;
}

int ploshad_pryamka(int a, int b){
    int S = a * b;
    return S;
}

int ploshad_pryamtreug(int a, int b){
    double S = (a*b)/2;
    return S;
}
int main()
{
    int choise;
    while (true){
        cout << "Choose the figure you want to find the area you want to find: \n1. Circle\n2. Rectangle\n3. Rectangular triangle\n0. Exit" << endl;
        cin >> choise;
        switch(choise){
             case 1:
                int r;
                cout << "Enter radius ";
                cin >> r;
                cout << "S = " << ploshad_krug(r) << endl;
                break;
            case 2:
                int a, b;
                cout << "Enter a ";
                cin >> a;
                cout << "Enter b ";
                cin >> b;
                cout << "S = " << ploshad_pryamka(a, b) << endl;
                break;
            case 3:
                int c, d;
                cout << "Enter c ";
                cin >> c;
                cout << "Enter c ";
                cin >> d;
                cout << "S = " << ploshad_pryamtreug(c, d) << endl;
                break;
            case 0:
                return 0;
            default:
                cout << "invailid input" << endl;
        }
    }
    return 0;
}
