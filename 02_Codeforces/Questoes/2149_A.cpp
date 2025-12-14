//14/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    ll n, a;
    while (t--) {
        cin >> n;

        ll saida = 0;
        ll contaNeg = 0;
        for (int i = 0; i < n; i++) {
            cin >> a;

            if (a == -1)
                contaNeg++;

            if (a == 0) 
                saida++;
        }

        if (contaNeg & 1)
            saida+=2;

        cout << saida << "\n";
    }

    return 0;
}