// 10/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    ll n, a;
    while (t--)
    {
        cin >> n;
        vi v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());
        if (n / 2 == 0)
        {
            n--;
        }

        string s = "YES";
        for(int i = 1; i < n-1; i+=2)
        {
            if (v[i] != v[i+1])
            {
                s = "NO";
                break;
            }
        }

        cout << s << "\n";

    }

    return 0;
}