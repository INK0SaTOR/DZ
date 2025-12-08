#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int n;
	cout << "vvedi kolichestvo simvolov v vectore" << endl;
	cin >> n;
	vector <int> vac;
    int vvod;

	for (int i; i <= n; i++)
	{
	    cout << "vvedi novoe chislo ";
	    cin >> vvod;
		vac.push_back(vvod);
	}
    sort(vac.begin(), vac.end());
	cout << "min = " << vac.front() << endl;
	cout << "max = " << vac.back() << endl;
}
