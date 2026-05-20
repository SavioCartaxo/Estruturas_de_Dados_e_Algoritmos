#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define readint(x) int x; cin >> x;
#define rep(i,a,b) for (int i = a; i < b; i++)
#define print(x) cout << x << '\n';

void solved() {
    string a;
    int n;
    cin >> a >> n;

    vi d(n);
    rep(i,0,n) cin >> d[i];
    sort(d.begin(), d.end());

    ll alvo = stoll(a);
    ll ans = (ll)4e18;
    int len = a.size();

    auto testa = [&](const string &s) {
        if (s.empty()) return;
        if (s.size() > 1 && s[0] == '0') return;
        ans = min(ans, llabs(alvo - stoll(s)));
    };

    int mn = d[0], mx = d.back();

    testa("0");

    if (len > 1) {
        string s(len - 1, char(mx + '0'));
        testa(s);
    }

    {
        int first = -1;
        for (auto x : d) {
            if (x != 0) {
                first = x;
                break;
            }
        }
        if (first != -1) {
            string s = "";
            s += char(first + '0');
            rep(i, 1, len + 1) s += char(mn + '0');
            testa(s);
        }
    }

    bool ok = true;
    for (char c : a) {
        int cur = c - '0';
        bool found = false;
        for (auto x : d) if (x == cur) found = true;
        if (!found) ok = false;
    }
    if (ok) testa(a);

    // Essa buceta ta certa?
    rep(pos, 0, len) {
        bool prefix_ok = true;
        rep(i, 0, pos) {
            int cur = a[i] - '0';
            bool found = false;
            for (auto x : d) if (x == cur) found = true;
            if (!found) prefix_ok = false;
        }

        if (!prefix_ok) continue;

        string prefix = a.substr(0, pos);
        int cur = a[pos] - '0';

        for (auto dig : d) {
            if (pos == 0 && len > 1 && dig == 0) continue;
            if (dig == cur) continue;

            string s = prefix;
            s += char(dig + '0');

            if (dig < cur) {
                rep(i, pos + 1, len) s += char(mx + '0');
            } else {
                rep(i, pos + 1, len) s += char(mn + '0');
            }

            testa(s);
        }
    }

    print(ans)
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    readint(t)
    while (t--) solved();

    return 0;
}