#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "how many input? -"
    cin << n;
    vector<int> v;
    v.push(0);
    cout <<"enter queue - ";
	for (int i=1; i<=n; i++)
	{
		int x;
		cin >> x;
		v.push(x); //queue add
	}
int head;
cout<<"head point- ";
cin<<head;
int hh = head;
int ans = 0;
cout << endl<< "total distance : ";
for (int i=1; i<= n; i++)
{
	int mn = min(v[i], head); //compare min max
	int mx = max(v[i], head);
	cout << "(" << mx << "-" << mn << ")";
	if (i<n)
		cout << "+";
    	ans += abs(v[i] - head);
		head = v[i];
	}
	cout << endl <<">"<< ans << " cylinders" << endl;
	cout << "path : ";
	for (int i= 0; i<= n; i++)
	{
		if (i == 0)
		{
			cout << hh << " ";
			continue;
		}
		cout << v[i] << " ";
	}
}



