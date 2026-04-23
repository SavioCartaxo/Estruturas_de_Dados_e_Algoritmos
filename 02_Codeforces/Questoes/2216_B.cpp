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
    ll t; cin >> t;
    while (t--) {
        ll t, h, u; cin >> t >> h >> u;
        ll out = 0;

        //tratando o U
        ll aux_u_t = min(u, t);
        out += aux_u_t * 4;
        t -= aux_u_t;
        u -= aux_u_t;

        //tratando o H
        ll auxht = min(h,t/2);
        out += auxht * 7;
        t -= auxht*2;
        h -= auxht;

        // caso especial
        if (h > 0 && t > 0) {
            out += 5;
            h -= 1;
            t -= 1;
        }

        // sobrou t
        if (t > 0) 
            out += 3 + ((t-1) * 2);
        
        out += 3 * (u + h);

        print(out)
    }

    return 0;
}