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

ll mdc(ll a, ll b) {
    if (a < b) swap(a, b);

    while(b != 0) {
        auto aux = a;
        a = b;
        b = aux % b;
    }

    return a;
}

ll mmc(ll a, ll b) {
    return a / mdc(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    readll(t)
    while(t--) {
        ll a, b, c, m;
        cin >> a >> b >> c >> m;

        auto ab  = m / mmc(a,b);
        auto ac  = m / mmc(a,c);
        auto bc  = m / mmc(b,c);
        auto abc = m / mmc(mmc(a, b), c);

        auto out1 = (6 * (m/a)) - (3 * (ab + ac)) + (2 * abc);
        auto out2 = (6 * (m/b)) - (3 * (ab + bc)) + (2 * abc);
        auto out3 = (6 * (m/c)) - (3 * (ac + bc)) + (2 * abc);
        
        print(out1 << ' ' << out2 << ' ' << out3)
    }
    
    return 0;
}