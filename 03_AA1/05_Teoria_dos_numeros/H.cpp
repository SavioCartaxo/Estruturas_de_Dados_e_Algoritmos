#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vb vector<bool>

const ll MAX = 1'000'000;

vb crivo() {
    vb primo(MAX + 1, true);
    primo[0] = primo[1] = false;

    for (ll j = 4; j <= MAX; j += 2) primo[j] = false;
    for (ll i = 3; (1LL*i*i) <= MAX; i+=2) {
        if (primo[i]) {
            for (ll j = (1LL*i*i); j <= MAX; j+=2*i) {
                primo[j] = false;
            }
        }
    }

    vb primo2(MAX + 1, false);
    for (ll i = 2; i <= MAX; i++) {
        if (primo[i]) {
            ll k = i;
            while (k <= MAX) {
                primo2[k] = true;
                k*=i;
            }
        }
    }

    return primo2;
}

bool is_prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll s = 0;
    vb v = crivo();

    if (is_prime(n)) {
        cout << 1 << endl;
        return 0;
    }

    for (ll i = 2; i <= MAX; i++) {
        if (v[i] && n % i == 0) {
            ll m = n;
            n /= i;
            s++;
            if (n == 1) 
                break;
        }
    }

    cout << s << endl;
    
    return 0;
}