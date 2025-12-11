// 11/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    ll n;
    while (t--) {
        cin >> n;

        vi v(n);
        vector<bool> vb(n, false);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        ll s = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (v[i] > v[j] && !vb[j]) {
                    vb[j] = true;
                    s++;
                }
            }
        }

        cout << s << "\n";
    }

    return 0;
}