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
    readint(t)
    while (t--) {
        readint(n)
        vi v(n);
        for (auto &i : v) {cin >> i;}

        int out = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] <= i + 1) out++;
        }

        print(out)
    }
    return 0;
}