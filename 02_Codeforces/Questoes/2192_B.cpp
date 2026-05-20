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
 
void printv(vi v) {
    
    rep (i, 0, (int)v.size()) {
        
        cout << v[i];
        if (i != (int)v.size() - 1) {
            cout << ' ';
        }

    }

    cout << endl;
}
 
void solved() {
    readint(n)
    vi v1, v0;
    int c1 = 0, c0 = 0;

    rep(i,1,n+1) {
        char a; cin >> a;

        if (a == '0'){
            v0.pb(i);
            c0++;
        } else {
            v1.pb(i);
            c1++;
        }
    }
 
    if (c1 == 0) {
        print(0)
        return;
    }

    if (c1 & 1 && !(c0 &1)) {
        print(-1)
        return;
    }

    if (!(c1 & 1) && !(c0 &1)) {
        print(c1)
        printv(v1);
    }

    if (c1 & 1 && c0 &1) {
        print(c0)
        printv(v0);
    }

    if (!(c1 & 1) && c0 & 1) {
        print(c1)
        printv(v1);
    }
}
 
int main() {
    readint(t)
    while (t--) {
        solved();
    }
    return 0;
}