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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    readint(t)
    while (t--) {
        ll n, k, p, m; cin >> n >> k >> p >> m;
        vl a(n+1);
        rep(i, 1, n+1) cin >> a[i];

        vl antes(a.begin()+1, a.begin()+p);
        sort(antes.begin(), antes.end());

        vl ciclo;
        rep(i, 1, n+1) {
            if (i != p) {
                ciclo.pb(a[i]);
            }
        }
        
        sort(ciclo.begin(), ciclo.end());

        ll primeiro = a[p];
        if (p > k) {
            rep(i, 0, p-k) { 
                primeiro += antes[i];
            }
        }

        if (primeiro > m) { print(0) continue; }
        m -= primeiro;

        ll per = a[p];
        rep(i, 0, n-k) per += ciclo[i];

        print(1 + m/per)
    }
    return 0;
}