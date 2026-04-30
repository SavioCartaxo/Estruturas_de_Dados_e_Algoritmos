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
        readint(n)
        vi v(n);
        for (auto &i : v) cin >> i;

        rep (i,0,n) {
            int m = 0;
            int M = 0;
            rep (j,i+1,n) {
                if (v[i] > v[j]) {
                    m++;
                } 
                
                if (v[i] < v[j]) {
                    M++;
                }
            }

            cout << max(m, M);

            if (i + 1 != n) 
                cout << ' ';
        }

        cout << endl;
    }
    return 0;
}