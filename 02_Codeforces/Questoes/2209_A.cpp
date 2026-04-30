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
        ll n, c, k; cin >> n >> c >> k;
        
        vl a(n);
        for(auto &i : a) cin >> i;
        sort(a.begin(), a.end());
        
        rep(i, 0, n) {
            if (a[i] <= c) {
                if (a[i] < c){
                    if (k >= abs(a[i] - c)) {
                        k -= abs(a[i] - c);
                        a[i] = c;
                    } else {
                        a[i] += k;
                        k = 0;
                    }
                }
                c += a[i];    
            } else {
                break;
            }
        }
        
        print(c)
    }
    return 0;
}