#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k, a;
    cin >> n >> k;

    vector<ll> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        v[i] = v[i-1] + a;
    }

    ll menor = (v[1+k-1]), im = 1;
    for (ll i = 1; i <= n - k + 1; i++) {
        if ((v[i+k-1] - v[i-1]) < menor) {
            menor = (v[i+k-1] - v[i-1]);
            im = i;
        }
    }

    cout << im << endl;

    return 0;
}