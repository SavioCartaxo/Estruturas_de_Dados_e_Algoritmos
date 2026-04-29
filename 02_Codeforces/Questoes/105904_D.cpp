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
    int n, m, p, s; 
    cin >> n >> m >> p >> s;

    vector<pair<int,int>> pares(m);
    for (auto &[a,b] : pares) {
        cin >> a >> b;
        a--, b--;
    }

    int out = 0;

    for (int sub = 0; sub < (1<<n); sub++) {
        int c = 0, xaxixa = 0;

        for (int i = 0; i < n; i++) {
            if (sub & (1<<i)) {
                if (i < p) c++;
                else if (i < p+s) xaxixa++;
            }
        }

        if (c != 1 || xaxixa != 1) continue;

        bool ok = true;
        for (auto [a,b] : pares) {
            if ((sub & (1<<a)) && (sub & (1<<b))) {
                ok = false;
                break;
            }
        }

        if (ok) out++;
    }

    print(out)
}