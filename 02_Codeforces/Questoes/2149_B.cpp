//14/12/2025

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
        for (int i = 0; i < n; i++) cin >> v[i];
        
        sort(v.begin(), v.end());

        ll saida = abs(v[0] - v[1]);
        for (int i = 0; i < n; i+=2) {
            saida = max(saida, abs(v[i] - v[i+1]));
        }

        cout << saida << "\n";
    }

    return 0;
}