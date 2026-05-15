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

    vl a(n);
    rep(i,0,n) cin >> a[i];
    sort(a.begin(), a.end());

    vl level(n);
    cin >> level[0];
    rep(i,1,n) {
        ll aux; cin >> aux;
        level[i] = level[i-1] + aux;
    }

    ll pontuacao_maxima = 0;

    rep(i,0,n) {
        ll x = a[i];
        ll espada = n - i;

        ll l = 0, r = n - 1, ans = -1;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (level[mid] <= espada) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        ll niveis = ans + 1;
        pontuacao_maxima = max(pontuacao_maxima, x * niveis);
    }

    print(pontuacao_maxima)
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    readint(t)
    while (t--) {
        solved();
    }
    return 0;
}