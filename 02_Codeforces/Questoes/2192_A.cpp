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
    reads(s)

    char dif = '0';
    int out = 0;
    bool tem_sequencia = false;
    for (auto c : s) {
        if (c != dif) {
            out++;
        } else {
            tem_sequencia = true;
        }
        dif = c;
    }

    if (s[0] != s.back() && out != 1 && tem_sequencia) {
        out++;
    }

    print(out)
}
 
int main() {
    readint(t)
    while (t--) {
        solved();
    }
    return 0;
}