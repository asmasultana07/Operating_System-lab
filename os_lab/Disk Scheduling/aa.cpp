//98 183 37 122 14 124 65 67

// FCFS
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout << "how many queue? - ";
	cin >> n;
	vector<int> v;
	v.push_back(0);
	cout <<"enter queue - ";
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x); //queue add
	}

	int h;
    cout <<" head points - ";
	cin >> h;
	int hh = h;
	int ans = 0;
	cout << endl<< "total distance : ";
	for (int i=1; i<= n; i++)
	{
		int mn = min(v[i], h);
		int mx = max(v[i], h);
		cout << "(" << mx << "-" << mn << ")";
		if (i<n)
			cout << "+";
		ans += abs(v[i] - h);
		h = v[i];
	}
	cout << endl <<">"<< ans << " cycles" << endl;
	cout << "path : ";
	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
		{
			cout << hh << " ";
			continue;
		}
		cout << v[i] << " ";
	}
}
