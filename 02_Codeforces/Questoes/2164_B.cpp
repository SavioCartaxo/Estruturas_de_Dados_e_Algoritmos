// 10/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    ll n, a;
    while (t--) {
        cin >> n;

        ll p1 = -1;
        ll p2 = -1;
        ll i1 = -1;
        ll i2 = -1;

        for (int i = 0; i < n; i++){
            cin >> a;

            if (a % 2 == 0) {
                if (p1 == -1) {
                    p1 = a;
                } else if (p2 == -1) {
                    p2 = a;        
                }
            } else {
                if (i1 == -1) {
                    i1 = a;
                } else if (i2 == -1) {
                    i2 = a;        
                }
            }
        }

        if (i1 != -1 && i2 != -1) {
            cout << i1 << ' ' << i2 << "\n";
        } else if (p1 != -1 && p2 != -1) {
            cout << p1 << ' ' << p2 << "\n";
        } else {
            cout << -1 << "\n";
        }

    }

    return 0;
}