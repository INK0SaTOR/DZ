#include <iostream>
#include <vector>
#include <algorithm>	
using namespace std;

int main()
{
	int n;
	cout << "skolko chisel budet v vektore?"<<endl;
	cin >> n;

	vector <int> vac;

	for (int i = 0; i < n; i++)
	{
		int t;
		cout << "vvedi novoe chislo ";
		cin>>t;
		vac.push_back (t);
	}

	cout << "first = " << vac.front() << endl;
	cout << "last = " << vac.back() << endl;

	cout << endl;

	swap(vac.front(), vac.back());

	cout << "first = " << vac.front() << endl;
	cout << "last	 = " << vac.back() << endl;
}
