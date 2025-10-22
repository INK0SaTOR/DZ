#include <iostream>
#include <vector>
#include <algorithm>	
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector <int> vac = { n };

	for (int i = 0; i <= n; i++)
	{
		vac.push_back(i);
	}

	vac.erase(vac.begin());

	cout << "min = " << vac.front() << endl;
	cout << "max = " << vac.back() << endl;

	cout << endl;

	swap(vac.front(), vac.back());

	cout << "first = " << vac.front() << endl;
	cout << "last	 = " << vac.back() << endl;
}
