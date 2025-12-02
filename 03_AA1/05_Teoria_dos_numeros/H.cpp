#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vb vector<bool>

const ll MAX = 1'000'000;

vb crivo() {
    vb primo(MAX + 1, true);
    primo[0] = primo[1] = false;

    for (ll i = 2; (1LL*i*i) <= MAX; i++) {
        if (primo[i]) {
            for (ll j = i*i; j <= MAX; j+=i) {
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll s = 0;
    vb v = crivo();

    for (int i = 2; i <= MAX; i++) {
        if (v[i] && n % i == 0) {
            n /= i;
            s++;
            if (n == 1) break;
        }
    }

    cout << s << endl;
    
    return 0;
}