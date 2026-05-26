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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    readint(n)
    vl v(n), dp(n);;
    rep(i,0,n) cin >> v[i];
    
    dp[0] = 1;
    ll ans = 1;
    rep (i, 1, n) {
        if (v[i] >= v[i-1]) {
            dp[i] = dp[i-1] + 1;
        } else {
            dp[i] = 1;
        }
        ans = max(ans, dp[i]);
    }
    print(ans)
    return 0;
}