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

int main() {
    readll(n)

    if (n < 2) {
        return 0;
    }

    vector<bool> vb(n+1, true);

    vb[0] = vb[1] = false;
    
    for (int i = 2; i <= n; i++) {
        if (vb[i]) {
            ll aux = 2*i;
            while (aux <= n) {
                vb[aux] = false;
                aux += i;
            }
        }
    }

    rep (i, 0, n+1) {
        if (vb[i]) cout << i << ' ';
    }

    return 0;
}