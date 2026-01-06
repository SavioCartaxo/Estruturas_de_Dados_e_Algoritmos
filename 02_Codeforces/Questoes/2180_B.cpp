// 05/01/2026

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i++)
#define endl '\n'
#define ll long long
#define vi vector<ll>
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define MAX 200'000
#define readll(x) ll x; cin >> x;
#define reads(x) string x; cin >> x;
#define print(x) cout << x << endl;

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

vector<bool> crivo() {
    // vou tentar fazer com set, mas vetor com busca binaria é mais eficiente
    vector<bool> vb(MAX + 1, true);
    vb[0] = vb[1] = 0;
    for (ll i = 4; i <= MAX; i+= 2) vb[i] = false;
    for (ll i = 3; i*i <= MAX; i+=2) {
        if (vb[i]) {
            for (ll j = i*i; j <= MAX; j+=2*i) {
                vb[j] = false;
            }
        }
    }

    return vb;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);

    readll(t)
    while (t--) {
        string s = "";
        readll(n);

        while(n--) {
            reads(s2)
            if ((s2 + s) < (s + s2)) s = s2 + s;
            else s = s + s2;
        }

        print(s);
    }

    return 0;
}