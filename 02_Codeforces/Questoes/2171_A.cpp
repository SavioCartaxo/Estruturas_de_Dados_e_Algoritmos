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

        if (n % 2 == 1) {
            cout << 0 << "\n";
            continue;
        }
        
        ll g = n / 2;
        ll v = n / 4;

        ll s = 0;
        if (v == 0) {
            s = g;
        } else {
            s = v + 1;
        }

        cout << s << "\n";
    }
    return 0;
}