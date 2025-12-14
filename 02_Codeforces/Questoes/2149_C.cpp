// 14/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    ll n, k;
    while (t--) {
        cin >> n >> k;
        
        ll valor;
        ll nK = 0;
        vector<bool> vb(k+1, false);
        for (int i = 1; i <= n;i++) {
            cin >> valor;

            if (valor <= k) {
                vb[valor] = true;

                if (valor == k) {
                    nK++;
                }
            }
        }

        ll saida = 0;
        for (int i = 0; i < k; i++) {
            if (!vb[i]) {
                saida++;
                if (nK > 0) nK--;
            }
        }

        saida += nK;
        
        cout << saida << "\n";
    }

    return 0;
}