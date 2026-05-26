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

void solved() {
    readint(n)
    ll mx = 0;
    rep(i,0,n) {
        readll(a)
        mx = max(mx, a);
    }
    print(mx * n)
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    readint(t)
    while (t--) solved();
    return 0;
}