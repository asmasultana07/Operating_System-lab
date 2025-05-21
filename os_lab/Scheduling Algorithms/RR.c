include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
        mp[i] = 0;
    int avg = 0, anss = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[i + 1] = 0;
    }
    int Q;
    cin >> Q;
    cout << "0 ";
    int sum = 0;
    while (true)
    {
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0)
                continue;
            if (v[i] >= Q)
            {
                sum += Q;
                v[i] -= Q;
                flag = 1;
            }
            else
            {
                sum += v[i];
                v[i] = 0;
            }

            cout << "p" << i + 1 << " " << sum << " ";
            mp[i + 1] = sum - mp[i + 1];
        }
        if (flag == 0)
            break;
    }
    for (int i = 1; i <= n; i++)
    {
        anss += mp[i];
    }
    cout << endl
         << anss / n << endl;
}
