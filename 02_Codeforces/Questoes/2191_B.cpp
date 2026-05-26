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
 
void solved() {
    readint(n)
    vi v(n);
    for (auto &i : v) cin >> i;
    sort(v.begin(), v.end());
 
    vi dpMexIndo(n);
    vector<bool> vb(n+1, false);
 
    rep (i, 0, n) {
        vb[v[i]] = true;
 
        rep (j,0,n+1) {
            if (!vb[j]) {
                dpMexIndo[i] = j;
                break;
            }
        }
    }
 
    vi dpMexVoltando(n);
    vb.assign(n+1, false);
    for (int i = n-1; i >= 0; i--) {
        vb[v[i]] = true;
 
        rep (j,0,n+1) {
            if (!vb[j]) {
                dpMexVoltando[i] = j;
                break;
            }
        }
    }
 
    rep (i, 0, n-1) {
        if (dpMexIndo[i] == dpMexVoltando[i+1]) {
            NO
            return;
        }
    }
 
    YES
}
 
// sorta
// ve se segue as regras
 
int main() {
    readint(t)
    while (t--) {
        solved();
    }
    return 0;
}