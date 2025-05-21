///SCAN ALGORITHM
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
	cout << "how many queue? - ";
    cin >> n;
    vector<int> v(n + 2);
    int lo = 0, hi = 199;
    v[0] = lo;
    cout <<"enter queue - ";
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    v[n + 1] = hi;

    int head;
    cout <<" head points - ";
    cin >> head;
    sort(v.begin(), v.end(), greater<int>());
    vector<int> ans;
    ans.push_back(head);
    for (int i = 0; i <= n + 1; i++)
    {
        if (v[i] < head)
            ans.push_back(v[i]);
    }
    for (int i = n; i > 0; i--)
    {
        if (v[i] > head)
            ans.push_back(v[i]);
    }

    int total_head_mov = 0;
    cout << endl<< "total distance : ";
    for (int i = 0; i < ans.size() - 1; i++)
    {
        total_head_mov += abs(ans[i] - ans[i + 1]);
        cout << "(" << max(ans[i], ans[i + 1]) << "-"
             << min(ans[i], ans[i + 1]) << ") ";
        if (i < ans.size() - 2)
            cout << "+";
    }
    cout << endl;
    cout << total_head_mov << " Cylinders." << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}
int main()
{
    solve();
}

