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

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);

    while (b) {
        a = a % b;
        swap(a, b);
    }

    return a;
}

ll mmc(ll a, ll b) {
    return a / gcd(a, b) * b;
}

void solved() {
    int n; cin >> n;
    vl a(n);
    for (auto &i : a) cin >> i;
    for (auto &i : a) cin >> i;

    if (n == 1) {
        print(0)
        return;
    }

    ll out = 0;
    for (int i = 0; i < n; i++) {
        ll limite;
        
        if (i == 0) 
            limite = gcd(a[0], a[1]);

        else if (i == n-1) 
            limite = gcd(a[n-2], a[n-1]);
        
        else {
            ll A = gcd(a[i-1], a[i]);
            ll B = gcd(a[i], a[i+1]);
            limite = mmc(A, B);
        }
        if (limite < a[i]) out++;
    }

    print(out)
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solved();
    return 0;
}