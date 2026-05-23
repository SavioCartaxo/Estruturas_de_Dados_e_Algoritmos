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

ll solved() {
    ll n, h, k;
    cin >> n >> h >> k;

    vl v(n+1);
    ll ciclo = 0;

    rep(i,1,n+1) {
        cin >> v[i];
        ciclo += v[i];
    }

    ll ciclos_usados = (h-1) / ciclo;
    ll out = ciclos_usados * (n + k);
    h -= ciclos_usados * ciclo;

    vl suf(n+2, 0);
    for (int i = n; i >= 1; i--) {
        suf[i] = max(suf[i+1], v[i]);
    }

    ll menor = 1e9;
    ll soma = 0;
    rep(i,1,n+1) {
        menor = min(menor, v[i]);
        soma += v[i];

        ll melhor = soma;
        ll Max = suf[i+1];
        if (Max > menor) {
            melhor = soma - menor + Max;
        }

        if (melhor >= h) {
            return out + i;
        }
    }

    return -1;
}

int main() {
    readint(t)
    while (t--) {
        print(solved());
    }
    return 0;
}