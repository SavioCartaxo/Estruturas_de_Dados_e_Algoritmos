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

#define rep(i,a,b) for (int i = a; i < b; i++)
#define repneg(i,a,b) for (int i = a; i > b; i--)

#define print(x) cout << x << endl;

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solved() {
    int n; cin >> n;
    
    int ans = 0;
    int cont1 = 0, cont2 = 0;
    rep (i, 0, n) {
        int a; cin >> a;
        if (a == 0) {ans++;}
        if (a == 1) {cont1++;}
        if (a == 2) {cont2++;}
    }

    int sub = min(cont1, cont2);
    ans += sub;
    cont1 -= sub;
    cont2 -= sub;

    ans += cont1 / 3;
    ans += (cont2 / 3);
    print(ans)
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    readint(t)
    while (t--) {
        solved();
    }
    return 0;
}