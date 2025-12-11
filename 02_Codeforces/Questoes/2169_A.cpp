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
        cin >> n >> a;

        ll maior = 0;
        ll menor = 0;
        ll aux;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            if (aux < a) {
                menor++;
            } else if (aux > a) {
                maior++;
            }
        }

        ll s;
        if (maior > menor) {
            s = a+1;
        } else {
            s = a-1;
        }

        cout << s << "\n";
    }

    return 0;
}