#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define b bool

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; 
    cin >> t;

    ll n;
    while (t--) {
        cin >> n;
        vi v(n);

        b par = false;
        b impar = false;

        for (int i = 0; i < n; i++) {
            cin >> v[i];

            if (v[i] % 2 == 0) {
                par = true;
            } else {
                impar = true;
            }
        }

        if (par && impar) {
            sort(v.begin(), v.end());
        }

        cout << v[0];
        for (ll i = 1; i < n; i++) {
            cout << ' ' << v[i];
        }
        cout << endl;
    }

    return 0;
}