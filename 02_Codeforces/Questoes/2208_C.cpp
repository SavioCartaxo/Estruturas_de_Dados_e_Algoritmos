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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<pair<int,int>> v(n);
        for (auto &[a, b] : v) {
            cin >> a >> b;
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b){
            if (a.second != b.second) return a.second < b.second;
            return a.first > b.first;
        });

        vector<long double> dp(n+1, 0);

        for (auto [c, p] : v) {
            long double mult = (1.0 - p / 100.0);
            for (int k = n; k >= 1; k--) {
                dp[k] = max(dp[k], dp[k-1] * mult + c);
            }
        }

        long double saida = 0;
        for (int i = 0; i <= n; i++) {
            saida = max(saida, dp[i]);
        }

        cout << fixed << setprecision(10) << saida << "\n";
    }
}