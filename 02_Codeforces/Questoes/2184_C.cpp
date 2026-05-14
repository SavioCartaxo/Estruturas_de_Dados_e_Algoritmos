#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define vll vector<vl>
#define vi vector<int>
#define vii vector<vi>

#define endl "\n"
#define pb push_back

#define rep(i,a,b) for (int i = a; i < b; i++)
#define rep4(i,a,b,c) for (int i = a; i < b; i+=c)

#define print(x) cout << x << endl;

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void dfs(ll n, set<ll> &s) {
    if (n < 3)
        return;

    ll n1, n2;
    n1 = n/2;
    if (n & 1) n2 = n/2 + 1; 
    else n2 = n/2;
    
    if (!s.count(n1)) dfs(n1, s);
    if (!s.count(n2)) dfs(n2, s);

    s.insert(n1); s.insert(n2);
}
 
void solved() {
    ll n, k; cin >> n >> k;
 
    if (n == k) {print(0) return;}
    if (k > n) { print(-1) return;}

    set<ll> s;
    s.insert(1); s.insert(2);
    dfs(n, s);
    
    if (s.count(k)) {
        int out = 0;
        while (n / 2 > k) {
            n /= 2;
            out++;
        }

        if (k != n) out++;
        print(out);
        return;
    }
    print(-1)
}
 
int main() {
    ll t; cin >> t;
    while (t--) {
       solved();
    }
    return 0;
}