#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define vll vector<vl>

#define readll(x) ll x; cin >> x;
#define readint(x) int x; cin >> x;
#define reads(x) string x; cin >> x;
#define readc(x) char x; cin >> x;

#define endl "\n"
#define pb push_back

#define rep(i,a,b) for (int i = a; i < b; i++)
#define rep4(i,a,b,c) for (int i = a; i < b; i+=c)
#define repneg(i,a,b) for (int i = a; i > b; i--)
#define repneg4(i,a,b,c) for (int i = a; i > b; i-=c)

#define print(x) cout << x << endl;

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

#define MAX 200000
vector<ll> crivo() {
    vector<ll> v = {1, 2};
    vector<bool> vb(MAX+1, true);

    vb[0] = vb[1] = false;

    for (ll i = 4; i <= MAX; i+=2) {
        vb[i] = false;
    }

    for (ll i = 3; i*i <= MAX; i+=2) {
        if (vb[i]) {
            ll aux = i*2;
            while (aux <= MAX) {
                vb[aux] = false;
                aux += i;
            }
        }
    }

    for (ll i = 3; i <= MAX; i+=2) {
        if (vb[i]) v.pb(i);
    }

    return v;
}

int main() {
    readint(t)
    auto p = crivo();
    while (t--) {
        readll(n)
        rep (i, 0, n) {
            cout << p[i] * p[i+1];
            if (i != n - 1) { cout << ' ';}           
        }
        cout << endl;
    }
    return 0;
}