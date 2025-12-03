#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k, a;
    cin >> n;

    vi v(n + 1); v[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        v[i] = v[i-1] + a;
    }

    ll mid;
    cin >> k;
    while (k--) {
        cin >> a;

        ll i = 0;
        ll f = n;

        while (i <= f) {
            mid = (i + f) / 2;

            if (a <= v[mid]) {
                f = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        
        cout << f+1 << endl;
    }

    return 0;
}