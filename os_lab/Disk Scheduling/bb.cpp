/// SSTF
#include <bits/stdc++.h>
#define INF 1000
using namespace std;
////98 183 37 122 14 124 65 67
int main()
{
	int n;
	cout << "how many queue? - ";
	cin >> n;
	vector<int> v(n);
	cout <<"enter queue - ";
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int head;
	 cout <<" head points - ";
	cin >> head;
	int cnt = 0;
	int mn = INF, flag, a;
	vector<int> ans;
	ans.push_back(head);
	while (true)
	{
		cnt++;
		for (int i = 0; i < n; i++)
		{
			if (v[i] != 0)
			{
				if (mn > abs(v[i] - head))
				{
					mn = abs(v[i] - head);
					flag = v[i];
					a = i;
				}
			}
		}
		mn = INF;
		ans.push_back(flag);
		v[a] = 0;
		if (cnt == n)
			break;
	}
	int cylinders = 0;
	cout << endl<< "total distance : ";
	for (int i = 0; i < ans.size() - 1; i++)
	{
		int mx = max(ans[i], ans[i + 1]);
		int mn = min(ans[i], ans[i + 1]);
		cylinders += (mx - mn);
		cout << "(" << mx << "-" << mn << ")";
		if (i < ans.size() - 2)
			cout << "+";
	}
	cout << endl << ">"<< cylinders << " cylinders." << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		if (i == 0)
			cout << "Path : ";
		cout << ans[i] << " ";
	}
}


