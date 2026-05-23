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

#define YES cout << "FHTAGN!" << endl;
#define NO cout << "NO" << endl;

vll grafo;
vector<bool> vb;
bool ciclo = false;

void dfs(ll v) {
    vb[v] = true;
    for (auto u : grafo[v]) {
        if (!vb[u]){
            dfs(u);
        } else if (u != v) {
            ciclo = true;
        }
    }
}

int main() {
    // Formalmente, consideraremos como Cthulhu qualquer grafo não direcionado que possa ser representado como um conjunto de três ou mais árvores enraizadas, cujas raízes estão conectadas por um ciclo simples.

    cin.tie(0)->sync_with_stdio(0);
    ll n, m; cin >> n >> m;
    grafo.assign(n+1, vl());
    vb.assign(n+1, false);

    rep (i, 0, m) {
        ll a, b; cin >> a >> b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }

    dfs(1);
    rep (i, 1, n+1) {
        if (!vb[i]) {
            NO
            return 0;
        }
    }

    // a partir daqui o grafo é conexo 100% de certeza
    if (ciclo && n == m) {
        YES
        return 0;
    }

    NO

    return 0;
}