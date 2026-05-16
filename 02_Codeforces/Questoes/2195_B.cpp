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
    vl v(n+1); 
    rep (i,1,n+1) 
        cin >> v[i];
    
    rep (i, 1, n + 1) {
        int aux = 2 * i;
        if (aux > n) break;
        
        while (v[i] != i && aux <= n) {
            if (v[i] > v[aux]) {
                swap(v[i], v[aux]);
            }
            aux *= 2;
        }
    }
 
    for (int i = 1; i < n + 1; i++) {
        if (v[i] != i) {
            NO
            return;
        }
    }
    
    YES
}
 
int main() {
    readint(t)
    while (t--) {
        solved();
    }
    return 0;
}