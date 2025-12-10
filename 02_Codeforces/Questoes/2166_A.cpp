// 10/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;

    char c;
    ll a;
    while (n--) {

        cin >> a;
        ll b = a;

        map<char, ll> m;
        while (b--){
            cin >> c;
            m[c]++;
        }

        cout << a - m[c] << "\n";
    }

    return 0;
}