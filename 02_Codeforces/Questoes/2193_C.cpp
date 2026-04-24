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
    readint(t)
    while (t--) {
        int n, q; cin >> n >> q;

        vi a(n), b(n);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;

        if (a[n-1] < b[n-1]) {
            a[n-1] = b[n-1];
        }

        for (int i = n - 2; i >= 0; i--) {
            a[i] = max(max(a[i+1], b[i]), a[i]);
        }

        for (int i = 0; i < n; i++) {
            if (i == 0) continue;
            a[i] += a[i-1];
        }

        while(q--) {
            int l, r; cin >> l >> r; l--; r--;
            
            if (l == 0) cout << a[r];
            else cout << a[r] - a[l-1];

            if (q - 1 >= 0) {
                cout << ' ';
            }
        }

        cout << endl;

    }
    return 0;
}