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

        string s;
        char c;
        for (int i = 0; i < n; i++) {
            cin >> c;
            s.push_back(c);
        }

        for (int i = 0; i < n; i++) {
            s.push_back(s[i]);
        }

        ll nzeros = 0;
        ll saida = 0;

        for (int i = 0; i < 2*n; i++) {

            if (s[i] == '0') {
                nzeros++;
            } else {
                saida = max(saida, nzeros);
                nzeros = 0;

                if (i >= n) {
                    break;
                }
            }
        }

        cout << saida << "\n";
    }

    return 0;
}