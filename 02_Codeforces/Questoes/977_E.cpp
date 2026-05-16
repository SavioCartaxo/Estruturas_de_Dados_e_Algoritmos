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

#define rep(i,a,b) for (int i = a; i < b; i++)
#define repneg(i,a,b) for (int i = a; i > b; i--)

#define print(x) cout << x << endl;

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

vii grafo;
vector<bool> vizitado;

bool dfs(int inicio, bool &ok) {
    vizitado[inicio] = true;

    // se o grau do vertive não é 2, não é um ciclo simples
    if (!(grafo[inicio].size() == 2)) {
        ok = false;
    }

    for (auto vizinho : grafo[inicio]) {
        if (!(vizitado[vizinho])) {
            dfs(vizinho, ok);
        }
    }

    return ok;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m; cin >> n >> m;
    grafo.assign(n+1, vi());
    vizitado.assign(n+1, false);

    rep (i, 0, m) {
        int a, b; cin >> a >> b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }

    int ans = 0;
    rep (i, 1, n+1) {
        if (!vizitado[i]) {
            bool ciclo = true;
            if (dfs(i, ciclo)) {
                ans++;
            }
        }
    }

    print(ans);
    
    return 0;
}