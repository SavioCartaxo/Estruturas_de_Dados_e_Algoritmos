#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define vb vector<bool>
#define pb push_back
#define MAX 100'000'000

vi crivo() {
    vb primos(MAX + 1, true);
    primos[0] = primos[1] = false;

    for (int j = 4; j <= MAX; j += 2) primos[j] = false;
    for (int i = 3; (1LL*i*i) <= MAX; i+=2) {
        if (primos[i]) {
            for (int j = (1LL*i*i); j <= MAX; j+=2*i) {
                primos[j] = false;
            }
        }
    }

    vi l;
    for (int i = 2; i <= MAX; i++) {
        if (primos[i]) {
            l.pb(i);
        }
    }

    return l;
}

pair<vi, vi> saida() {
    vi v = crivo();
    vi lin(MAX+1, 0);
    vi col(MAX+1, 0);

    ll idx = 0, l = 1;
    while (idx < (ll)v.size()) {
        ll c = 1;
        for (ll j = 0; j < l && idx < (ll)v.size(); j++) {
            int p = v[idx++];
            lin[p] = l;
            col[p] = c++;
        }
        l++;
    }
    return {lin, col};
}

int main() {
    pair<vi, vi> p = saida();
    auto l = p.first;
    auto c = p.second;
    
    ll t, a, s; cin >> t;
    while (t--) {
        cin >> a;
        
        if (l[a] != 0) {
            cout << l[a] << ' ' << c[a] << "\n";
        } else {
            cout << -1 << "\n";
}

    }

    return 0;
}
