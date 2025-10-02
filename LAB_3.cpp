#include <iostream>

using namespace std;

int fact(int n){
    int res = 1;
    for (int i = 2; i <= n; i ++){
        res *= i;
    }
    return res;
}
int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    int res = 0;
    for (int i = n; i <= m; i ++){
        if (i%2==0){
            res += fact(i);
        }
    }
    cout << res;
    return 0;
}
