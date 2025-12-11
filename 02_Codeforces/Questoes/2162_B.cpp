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

        string str; cin >> str;

        ll s = 0;

        vi saida;
        for (int i = 0; i < n; i++) {
            if (str[i] == '0') {
                s++;
                saida.push_back(i+1);
            }
        }

        cout << s << "\n";
        for (int i = 0; i < (int) saida.size(); i++) {
            cout << saida[i];

            if (i != (int) saida.size() - 1) {
                cout << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}