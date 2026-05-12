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
 
vector<vl> adj;
vl cor;
ll cont1, cont2;

bool dfs(ll u, ll p) {
    bool ok = true;
    
    if (cor[u] == -1) {
        if (cor[p] == 1) {
            cor[u] = 2;
            cont2++;
        } else {
            cor[u] = 1;
            cont1++;
        }
    }
    
    for (ll v : adj[u]) {
        if (cor[v] == -1 && !dfs(v, u) || cor[v] == cor[u]) {
            ok = false;
        }
    }
    
    return ok;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    readll(t)
    while (t--) {
        readll(n) readll(m)
    
        adj.assign(n+1, vl());
        cor.assign(n+1, -1);
    
        rep(i, 0, m) {
            readll(a) readll(b)
            adj[a].pb(b);
            adj[b].pb(a);
        }
    
        ll out = 0;
    
        rep(l, 1, n+1) {
            cont1 = 0;
            cont2 = 0;

            if (cor[l] == -1) {
                cont1++;
                cor[l] = 1;
                if (dfs(l, 0)) {
                    out += max(cont1, cont2);
                }
            }
        }
    
        print(out)
    }
    
    return 0;
}