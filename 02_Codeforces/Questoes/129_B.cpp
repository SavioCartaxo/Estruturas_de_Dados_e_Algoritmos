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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m; cin >> n >> m;
    vii grafo(n+1);
    rep (i, 0, m) {
        int a, b; cin >> a >> b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }

    vector<bool> expulso(n+1, false);
    bool mudou = true;
    int ans = 0;
    while (mudou){
        mudou = false;
        rep (i, 1, n+1) {
            auto vizinhos = grafo[i];

            if ((int) vizinhos.size() == 1) {
                expulso[i] = true;
                mudou = true;
            }
        }

        rep (i, 1, n+1) {
            auto vizinhos = grafo[i];
            if (expulso[i] && (int) vizinhos.size() == 1) {
                auto vizinho = vizinhos[0];
                grafo[i].erase(find(grafo[i].begin(), grafo[i].end(), vizinho));
                grafo[vizinho].erase(find(grafo[vizinho].begin(), grafo[vizinho].end(), i));
            }
        }

        ans++;
    }

    print(ans-1);
    return 0;
}