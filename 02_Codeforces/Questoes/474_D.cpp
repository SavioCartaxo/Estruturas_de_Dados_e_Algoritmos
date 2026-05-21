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
 
#define MOD 1000000007
#define MAXFACT 100001

ll k;
vl fat(MAXFACT);
vl inv_fat(MAXFACT);

ll fact(int n) {
    return fat[n];
}

ll inverso_modular(ll a) {
    return inv_fat[a];
}

ll binpow(ll a, ll b) {
    ll out = 1;
    a = a % MOD;
    while (b) {
        if (b & 1) out = (out * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return out % MOD;
}

void building() {
    fat[0] = 1;
    rep(i, 1, MAXFACT) fat[i] = fat[i-1] * i % MOD;
    
    inv_fat[MAXFACT-1] = binpow(fat[MAXFACT-1], MOD-2);
    for (int i = MAXFACT-2; i >= 0; i--)
        inv_fat[i] = inv_fat[i+1] * (i+1) % MOD;
}

ll combinatoria(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return fat[n] % MOD * inv_fat[k] % MOD * inv_fat[n-k] % MOD;
}

void solved() {
    ll a, b; cin >> a >> b;

    ll out = 0;
    for (int i = a; i < b + 1; i++) {
        ll quantidade_grupos = i / k;
        rep (grupo_atual, 0, quantidade_grupos + 1) {
            ll r = i - (grupo_atual * k);
            out = (out + combinatoria(r + grupo_atual, grupo_atual)) % MOD;
        }
    }

    print(out)
}

int main() {
    ll t; cin >> t >> k;
    building();
    while (t--) {
        solved();
    }
    return 0;
}