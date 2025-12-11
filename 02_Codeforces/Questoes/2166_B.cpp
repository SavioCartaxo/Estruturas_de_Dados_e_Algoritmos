// 10/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    double a, b, n;
    while (t--) {
        cin >> a >> b >> n;
        
        ll s = 1;
        if (b > (a/n) && a != b) s++;
        cout << s << "\n";

    }

    return 0;
}