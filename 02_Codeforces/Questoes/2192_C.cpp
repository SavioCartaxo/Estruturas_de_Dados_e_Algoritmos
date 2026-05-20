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
 
void printv(vi v) {
    
    rep (i, 0, (int)v.size()) {
        
        cout << v[i];
        if (i != (int)v.size() - 1) {
            cout << ' ';
        }

    }

    cout << endl;
}
 
ll solved() {
    ll n, h, k; cin >> n >> h >> k;

    vl v(n+1);
    ll ciclo = 0;
    set<ll> valores;
    map<ll, ll> m; // valor : posicao
    vl sum(n+1);
    sum[0] = 0;
    rep (i ,1 , n+1) {
        cin >> v[i];
        ciclo += v[i];
        valores.insert(v[i]);
        m[v[i]] = i;

        sum[i] = v[i];
        if (i != 1) {
            sum[i] = sum[i] + sum[i-1];
        }
    }

    ll out = 0;

    // Tempos de recarga
    if (h % ciclo == 0) { 
        out += max(k * (h / ciclo - 1), 0LL);
    } else {
        out += k * (h / ciclo);
    }

    // as balas de cada ciclo fechado
    out += (h / ciclo) * ciclo; 

    h = h % ciclo;
    if (h == 0) {
        return out;
    }
    
    // faz a troca
    rep (i, 1, n+1) {
        ll soma_atual = sum[i-1];
        ll numero_buscaso = h - soma_atual;
        
        if (valores.count(numero_buscaso) && m[numero_buscaso] <= i) {
            swap(v[i], v[m[numero_buscaso]]);
            out += i;
            return out;
        }
    }

    // não fez troca
    rep (i, 1, n+1) {
        h -= v[i];
        out++;

        if (h <= 0) {
            break;
        }
    }

    return out;
}
 
int main() {
    readint(t)
    while (t--) {
        print(solved());
    }
    return 0;
}