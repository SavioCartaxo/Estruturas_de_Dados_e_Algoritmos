#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define vb vector<bool>
#define pb push_back
#define MAX 1e6

vi crivo() {
    // Os números T- primos são os quadrados dos números primos

    vb prime(MAX + 1, true);
    prime[0] = prime[1] = false;

    for (ll i = 2; (1LL * i * i) <= MAX; i++) {
        if (prime[i]) {
            for (ll j = i*i; j <= MAX; j+=i) {
                prime[j] = false; // tomar cuidado para não confundir i com j
            }
        }
    }

    vi prime3 = {};
    for (ll i = 0; i <= MAX; i++) {
        if (prime[i]) {
            prime3.pb(i*i);
        }
    }

    return prime3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, a;
    cin >> n;

    vi c = crivo();

    while (n--) {
        cin >> a;

        string s = "NO";
        ll i = 0;
        ll f = (ll) c.size();

        while (i <= f) {
            ll mid = (i + f) / 2;
            if (c[mid] == a) {
                s = "YES";
                break;
            }

            if (a >= c[mid]) {
                i = mid + 1;
            } else {
                f = mid - 1;
            }
        }
        cout << s << endl;
    }

    return 0;
}