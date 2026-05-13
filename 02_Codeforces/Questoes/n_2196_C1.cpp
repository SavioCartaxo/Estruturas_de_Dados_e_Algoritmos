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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    readint(t)
    while (t--) {
        readint(n)
        set<pair<ll,ll>> arestas;
        ll k = 1;
        while (true) {
            cout << "? " << k << "\n" << flush;
            ll q; cin >> q;
            if (q == 0) break;
            vl v(q);
            rep(i, 0, q) cin >> v[i];
            rep(i, 0, q-1) arestas.insert({v[i], v[i+1]});
            k++;
        }
        cout << "! " << arestas.size() << "\n";
        for (auto [a, b] : arestas) cout << a << " " << b << "\n";
        cout << flush;
    }
    return 0;
}