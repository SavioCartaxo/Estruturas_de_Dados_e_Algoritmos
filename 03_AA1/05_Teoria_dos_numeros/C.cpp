#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define pb push_back

// Crivo linear que acha os primos até n
vi crivo(int n) {
    vi lp(n + 1, 0);
    vi primes;
    primes.reserve(n / 10);

    for (ll i = 2; i <= n; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.pb(i);
        }

        for (ll p : primes) {
            if (p > lp[i] || 1LL * p * i > n)
                break;
            lp[p * i] = p;
        }
    }

    return primes;
}

bool pri(vi &v, ll busc) {
    bool primo = false;
    
    // Busca binaria do primo
    ll ini = 0;
    ll fim = ((ll) v.size()) - 1;
    
    while (ini <= fim) {
        ll mid = (ini + fim) / 2;

        if (v[mid] == busc){
            primo = true;
            break;
        }

        if (v[mid] > busc) {
            fim = mid - 1;
        } else  {
            ini = mid + 1;
        }

    }

    return primo;
}

// o número é adorado?
bool adora(ll &num, vi &v) {
    string s = to_string(num);

    bool temZero = false;
    for (char c : s) {
        if (c == '0') {
            temZero = true; // adoram todos primos que tem 0
            break;
        }
    }

    if (temZero) {
        return true;
    }

    string aux;
    for (ll i = (ll) s.size() - 1; i >= 0; i--) {
        aux.insert(aux.begin(), s[i]);
        ll busc = stoll(aux);

        bool primo = pri(v, busc);

        if (!primo) {
            return true;
        }
    }

    return false;
}

vi saida(vi &v) {
    ll s = 0;
    vi vs((int) v.size());
    
    for (int i = 0 ; i < (int) v.size(); i++) {
        if (!adora(v[i], v)) {
            s++;
        }
        vs[i] = s;
    }

    return vs;
}

int main() {
    ll t, n;
    cin >> t;

    vi v = crivo(1e6);
    vi vs = saida(v);

    while (t--) {
        cin >> n;

        ll i = 0;
        ll f = v.size() - 1;
        ll s = -1;

        while (i <= f) {
            ll mid = (i + f) / 2;

            if (v[mid] <= n) {
                s = mid;
                i = mid + 1;
            } else {
                f = mid - 1;
            }
        }

        cout << vs[s] << endl;
    }

    return 0;
}