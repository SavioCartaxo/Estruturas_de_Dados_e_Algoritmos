//14/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    
    vi v(n+1);
    v[0] = 0;
    ll a;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        v[i] = v[i-1] + a;
    }

    ll saida = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[n] - v[i])
            saida++;
    }

    cout << saida << "\n";

    return 0;
}