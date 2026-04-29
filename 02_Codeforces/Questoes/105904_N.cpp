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

#define MAX 1e6 + 1

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    readint(n)

    vector<bool> degraus(MAX, false);
    vi saida(MAX, 0);
    multiset<int> ms;

    while (n--) {
        readint(a)

        vector<int> divs;

        for (int d = 2; d * d <= a; d++) {
            if (a % d == 0) {
                divs.pb(d);
                if (d != a/d) divs.pb(a/d);
            }
        }

        if (a > 1) divs.pb(a);

        for (int d : divs) {
            if (saida[d] > 0) ms.erase(ms.find(saida[d]));

            if (degraus[a]) saida[d]--;
            else saida[d]++;

            if (saida[d] > 0) ms.insert(saida[d]);
        }

        degraus[a] = !degraus[a];

        if (ms.empty()) print(0)
        else print(*ms.rbegin())
    }

    return 0;
}