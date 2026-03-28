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

ll mdc(ll a, ll b) {
    if (a < b) swap(a,b);

    while (a != 0) {
        ll aux = a;
        a = b;
        b = a % aux;
    }

    return b;
}

int main() {
    readll(t)

    vl v;
    rep (i,0,t) {
        readll(a)
        v.pb(a);
    }

    // MDC
    ll mdc = v[0];
    rep (i,1,t) {
           
    }
    return 0;
}