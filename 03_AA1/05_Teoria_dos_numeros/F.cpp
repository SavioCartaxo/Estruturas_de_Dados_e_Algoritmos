#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi  vector<ll>
#define MAX 1'000'000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x; cin >> n;
    vi v(MAX + 1, 0);

    for (ll i = 0; i < n; i++) {
        cin >> x;
        v[x]++;
    }

    for (ll i = MAX; i >= 1; i--) {
        ll c = 0;

        for (ll j = i; j <= MAX; j += i) {
            c += v[j];
            if (c >= 2) {
                cout << i << "\n";
                return 0;
            }
        }
    }

    return 0;
}
