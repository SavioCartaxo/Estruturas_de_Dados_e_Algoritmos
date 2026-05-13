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
    cin.tie(0)->sync_with_stdio(0);
    readint(t)
    while (t--) {
        readint(n)
        string s; cin >> s;

        vector<bool> vb(50, false);

        vb[0] = true;
        int out = 1;
        rep (i,1,n) {
            char c = s[i];
            
            if (c == 'R') {
                out++;
            }

            else {out++; break;}
        }

        print(out)
    }
    return 0;
}