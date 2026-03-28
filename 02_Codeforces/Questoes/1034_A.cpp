#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define vll vector<vl>

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

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);

    while (b != 0) {
        ll aux = a;
        a = b;
        b = aux % b;
    }

    return a;
}

int main() {
    ll n; cin >> n;
    vl v(n);

    ll mdc;
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        if (i == 0) 
            mdc = v[0];
        else 
            mdc = gcd(mdc, v[i]);
    }

    for (ll i = 0; i < n; i++) {
        v[i] = v[i] / mdc;
    }

    ll saida = 0;
    for (ll i = 0; i < n; i++) {
        if (v[i] <= mdc) {
            saida ++;
        }
    }

    if (saida == n || saida == 0) {
        print(-1)
    } else 
        print(saida)

    return 0;
}