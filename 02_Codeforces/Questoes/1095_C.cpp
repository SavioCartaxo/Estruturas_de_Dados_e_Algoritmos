#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define vll vector<vl>
#define vi vector<int>
#define vii vector<vi>

#define readll(x) ll x; cin >> x;
#define readint(x) int x; cin >> x;
#define reads(x) string x; cin >> x;

#define endl "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define rep(i,a,b) for (int i = a; i < b; i++)

#define print(x) cout << x << endl;

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

int binpow(int a, int b) {
    int out = 1;
    while (b) {
        if (b & 1) out *= a;
        a *= a;
        b >>= 1;
    }
    return out;
}

void printv(vi &v) {
    rep (i, 0, sz(v)) {
        cout << v[i];
        if (i != sz(v) - 1) {
            cout << ' ';
        }
    }
    print("")
}

void solved() {
    ll n, k;
    cin >> n >> k;
    
    if (k > n) {
        NO
        return;
    }

    ll numero_minimo = __builtin_popcountll(n);
    if (numero_minimo > k) {
        NO
        return;
    }

    if ((k - numero_minimo) & 1) {
        NO
        return;
    }

    YES

    vi bits;
    for (int i = 31; i >= 0; i--) {
        if (n & (1 << i)) {
            bits.pb(binpow(2,i));
        }
    }

    int pode_dividir = 0;
    k = k - numero_minimo;
    
    while (k--) {
        while (bits[pode_dividir] == 1) {
            pode_dividir++;
        }

        int numero = bits[pode_dividir];
        bits.erase(bits.begin() + pode_dividir);
        bits.pb(numero / 2);
        bits.pb(numero / 2);
    }

    printv(bits);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solved();
    return 0;
}

//__builtin_popcountll