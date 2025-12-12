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
        
        vi v(n + 1);

        ll valorPretendido;
        ll maior;
        for (int i = 1; i <= n; i++) {
            cin >> valorPretendido;
            
            if (i == 1) maior = valorPretendido;
            maior = max(maior, valorPretendido);

            if (i & 1) {
                v[i] = valorPretendido;
            } else {
                v[i] = maior;
            }
        }

        ll s = 0;
        for (int i = 1; i < n; i++) {
            
            if (i & 1 && v[i] >= v[i+1]) {
                s += v[i] - v[i+1] + 1;
            }

            if (!(i & 1) && v[i+1] >= v[i]) {
                s += v[i+1] - v[i] + 1 ;
                v[i+1] = v[i] - 1;
            }
        }

        cout << s << "\n";
    }

    return 0;
}