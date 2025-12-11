// 10/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

ll exponenciacaoBinaria(ll base, ll expoente) {
    ll s = 1;
    ll MOD = 1'000'000'007;

    while (expoente > 0) {
        if (expoente & 1) {
            s = (s * base) % MOD;
        }

        base = (base * base) % MOD;
        expoente >>= 1;
    }

    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    ll n;
    while (t--) {
        cin >> n;

        if (n == 1) cout << 1 << "\n";
        else cout << exponenciacaoBinaria(2, n-1) << "\n";
    }

    return 0;
}