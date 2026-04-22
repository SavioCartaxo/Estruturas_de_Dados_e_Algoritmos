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

int mdc(ll a, ll b) {
    if (a < b) swap(a,b);
    while (b != 0) {
        ll aux = a;
        a = b;
        b = aux % b;
    }
    return a;
}

int main() {
    readint(t)
    ll c,l,a,b;
    while(t--) {
        cin >> l >> c >> a >> b;

        auto b1 = mdc(a, l) == 1;
        auto b2 = mdc(b, c) == 1;
        auto b3 = mdc(l, c) < 3;

        if (b1 && b2 && b3) YES
        else NO
    }
    return 0;
}