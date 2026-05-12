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

#define  NEG -1e18

int main() {
    cin.tie(0)->sync_with_stdio(0);

    readll(n) readll(t)

    vll c(n, vl(t+1));
    rep(i,0,n) {
        rep(j,1,t+1) {
            cin >> c[i][j];
        }
    }

    readll(l) readll(u)

    vll pref(n, vl(t+1, 0));
    rep(i,0,n) {
        rep(j,1,t+1) {
            pref[i][j] = pref[i][j-1] + c[i][j];
        }
    }

    vll best(t+1, vl(t+1, 0));

    rep(i,1,t+1) {
        rep(j,i,t+1) {
            ll mx = 0;
            rep(k,0,n) {
                ll val = pref[k][j] - pref[k][i-1];
                mx = max(mx, val);
            }
            best[i][j] = mx;
        }
    }

    vl dp(t+1, NEG);
    dp[0] = 0;

    rep(i,1,t+1) {
        rep(k,l,u+1) {
            if (i - k < 0) continue;
            if (dp[i-k] == NEG) continue;

            dp[i] = max(dp[i], dp[i-k] + best[i-k+1][i]);
        }
    }

    if (dp[t] == NEG) print(-1)
    else print(dp[t]);

    return 0;
}

// Salvio ou Sarvio?