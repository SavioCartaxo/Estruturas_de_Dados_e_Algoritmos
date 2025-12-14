//14/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    ll n, m;
    while (t--) {
        cin >> n >> m;
    
        vi v(m); 
        for (int i = 0; i < m; i++) cin >> v[i];

        ll saida = 0;
        saida = n - v[m-1] + 1;

        for (int i = 0; i < m-1; i++) {
            if (v[i] >= v[i+1]){
                saida = 1;
                break;
            }
        }

        cout << saida << "\n";
    }

    return 0;
}