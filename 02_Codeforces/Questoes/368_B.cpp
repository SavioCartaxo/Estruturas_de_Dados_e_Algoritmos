//14/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, a; cin >> n >> m;
    
    vi v(n+1);
    vector<bool> vb(100'001);
    
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        vb[v[i]] = true;
    }

    ll dif = 0;
    for (int i = n; i > 0; i--) {
        if (vb[v[i]]) {
            vb[v[i]] = false;
            dif++;
        }
        v[i] = dif;
    }

    for (int i = 0; i < m; i++) {
        cin >> a;
        cout << v[a] << endl;
    }

    return 0;
}