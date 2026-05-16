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

int n;
vii grafo;
vi subarvore_problema;
vector<bool> problemas;

void calc(int v, int pai) {
    if (problemas[v]) subarvore_problema[v] = 1;
    else subarvore_problema[v] = 0;

    for (int u : grafo[v]) {
        if (u != pai) {
            calc(u, v);
            subarvore_problema[v] += subarvore_problema[u];
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    grafo.assign(n+1, vi());
    subarvore_problema.assign(n+1, 0);
    problemas.assign(n+1, false);

    rep(i, 1, n) {
        int a, b, c; cin >> a >> b >> c;
        
        grafo[a].pb(b);
        grafo[b].pb(a);

        if (c == 2) {
            problemas[a] = true;
            problemas[b] = true;
        }
    }

    calc(1, 0);

    vi lista_saida;
    rep(i, 2, n+1) {
        if (problemas[i] && subarvore_problema[i] == 1)
            lista_saida.pb(i);
    }

    print((int)lista_saida.size())
    rep(i, 0, (int)lista_saida.size()) {
        cout << lista_saida[i];
        if (i != (int)lista_saida.size()-1) cout << ' ';
    }
    cout << "\n";
    return 0;
}