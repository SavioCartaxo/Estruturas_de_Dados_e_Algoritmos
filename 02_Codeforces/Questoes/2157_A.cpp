// 10/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    ll n, a;
    while (t--) {
        cin >> n;
        map<ll, ll> m;

        for (int i = 0; i < n; i++) {
            cin >> a;
            m[a]++;
        }

        ll s = 0;
        for (auto i : m) {
            if (i.first != i.second) {
                if (i.first < i.second) {
                    s += i.second - i.first;
                } else {
                    s += i.second;
                }
            }
        }

        cout << s << "\n";

    }

    return 0;
}