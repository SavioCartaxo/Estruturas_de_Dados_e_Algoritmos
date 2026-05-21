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
    string t; int n; cin >> n >> t;

    if (sz(t) > n) {
        print(-1)
        return 0;
    }

    cout << t;
    for (int i = 0; i < n - sz(t); i++) {
        cout << '0';
    }

    cout << endl;

    return 0;
}