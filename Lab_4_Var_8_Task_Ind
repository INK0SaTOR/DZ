#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
    double minimum = INT_MAX;
	vector <double> vac;

    for (int i = 0; i <= n -1; i++){
        double a;
        cin >> a;
        vac.push_back(a);

    }

    for (int i = 0; i <=n -1; i++){
        if (minimum > vac[i]) {
            minimum = vac[i];
        }
    }
    cout << endl;
    cout << minimum << endl;
    cout << endl;

    double summa = 0;
    for (int i = 0; i <= n-1; i++){
        if (vac[i] < 0){
                while (vac[i+1] > 0){
                    summa += vac[i+1];
                    i++;
                }
            }
        }
    cout << endl;
    cout << summa << endl;
    cout << endl;

    for (int i = 0; i<=n-1; i++){
        vac[i] = abs(vac[i]);
    }
    sort(vac.begin(), vac.end());
    for(int i = 0; i <= n-1; i++){
        cout << vac[i] << " ";
    }
    return 0;
}
