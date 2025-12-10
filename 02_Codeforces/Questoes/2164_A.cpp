// 10/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1'000'000'000'000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    ll n, a, x;
    while (t--) {
        cin >> n;

        ll maior = -INF;
        ll menor = INF;
        while (n--) {
            cin >> a;

            maior = max(maior, a);
            menor = min(menor, a);
        }

        cin >> x;
        string s = "NO";
        if (menor <= x && x <= maior) {
            s = "YES";
        }

        cout << s << "\n";
    }

    return 0;
}