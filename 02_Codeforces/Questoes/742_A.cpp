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

#define MOD 10

ll binpow(ll a, ll b) {
    ll out = 1;
    a = a % MOD;
    while (b) {
        if (b & 1) out = (out * a) % MOD;
        a = (a * a) % MOD;
        b = b >> 1;
    }
    return out;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    print(binpow(1378, n))
    return 0;
}