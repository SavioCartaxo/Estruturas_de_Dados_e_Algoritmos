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
#define endl "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define rep(i,a,b) for (int i = a; i < b; i++)
#define print(x) cout << x << endl;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    ll n; cin >> n;
    priority_queue<ll> pq;
    rep(i,0,n){
        ll a; cin >> a;
        pq.push(a);
    }

    vl v = {pq.top()};
    vl freq = {1};
    int i = 0;
    while (!pq.empty()) {
        ll top = pq.top();
        
        if (v[i] == top) {
            freq[i]++;
        
        } else {
            v.pb(top);
            freq.pb(1);
            i++;
        }

        pq.pop();
    }

    // A partir daqui o problema vira : sabendo que v[i] tem peso freq[i], como
    // ter o máximo sem escolher vizinhos que se diferem em 1?

    ll out = 0;
    print(out)

    return 0;
}