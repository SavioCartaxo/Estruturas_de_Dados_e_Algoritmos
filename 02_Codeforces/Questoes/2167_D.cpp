// 10/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

ll mdc(ll a, ll b) {
    if (a < b) 
        swap(a, b);
    
    while (b != 0) {
        ll c = a;
        a = b;
        b = c % b;
    }

    return a;
}

vi crivo() {
    ll n = 1'000'000;
    vector<bool> v(n+1, true);
    v[0] = v[1] = false;

    for (ll i = 4; i <= n; i+=2) 
        v[i] = false;
    
    for (ll i = 3; i*i <= n; i+=2)
        for (ll j = i*i; j <= n; j+=2*i)
            v[j] = false;
        
    vi primos = {2};
    for (ll i = 3; i <= n; i+=2)
        if (v[i])
            primos.push_back(i);

    return primos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;
    vi primos = crivo();
    ll n;
    while (t--) {
        cin >> n;

        vi v(n);
        bool impar = false;
        for (ll i = 0; i < n; i++) {
            cin >> v[i];

            if (v[i] % 2 == 1) {
                impar = true;
            }
        }

        ll s;

        if (impar) {
            s = 2;
        } else {
            s = 1'000'000'000'000'000'000;
            for (ll p : primos) {
                for (ll i : v) {
                    if (mdc(i, p) == 1){
                        s = p;
                        break;
                    }
                }

                if (s != 1'000'000'000'000'000'000) {
                    break;
                }
            }

            if (s == 1'000'000'000'000'000'000) {
                s = -1;
            }
        }

        cout << s << "\n";
    }

    return 0;
}