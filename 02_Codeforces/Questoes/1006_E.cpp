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

vll grafo;
vl descendentes;

ll dfs(ll v) {
    ll aux = 0;
    for (auto u : grafo[v]) {
        aux += 1 + dfs(u);
    }
    descendentes[v] = aux;
    return aux;
}

ll predict(ll ui, ll ki) {

    // o primeiro da sequência é o próprio ui
    if (ki == 1) {
        return ui;
    }

    ki--;

    for (auto u : grafo[ui]) {

        // essa subárvore contém o k-ésimo elemento
        if (descendentes[u] + 1 >= ki) {
            return predict(u, ki);
        }

        // pula toda a subárvore
        ki -= descendentes[u] + 1;
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    ll n, q; cin >> n >> q;

    grafo.assign(n+1, vl());

    rep (i, 2, n+1) {
        ll a; cin >> a;
        grafo[a].pb(i);
    }
    
    for (auto &i : grafo) {
        sort(i.begin(), i.end());
    }

    descendentes.assign(n+1, 0);
    dfs(1);

    rep (i, 0, q) {
        ll ui, ki; cin >> ui >> ki;
        print(predict(ui, ki))
    }
    
    return 0;
}