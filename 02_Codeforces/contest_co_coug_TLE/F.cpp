#include "bits/stdc++.h"
using namespace std;
 
#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> pii;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    ll n; cin >> n;
    vi arr(n); rep(i, 0, n) cin >> arr[i];
    
    ll q; cin >> q; vi quer(q); rep(i, 0, q) cin >> quer[i];
    vi ans(q);
 
    map<ll, ll> freq;
 
    for(ll k = 0; k < n; k++){
        for(ll l = k+1; l < n; l++){
            ll kl = arr[k] + arr[l];
 
            for (ll xxx = 0; xxx < q; xxx++){
                ll falta = quer[xxx] - kl;
                if (freq.count(falta)){
                    ans[xxx] += freq[falta];
                }
            }
        }

        for(ll i = 0; i < k; i++){
            ll ij = arr[i] + arr[k];
            freq[ij]++;
        }
    }
    
    for (auto x : ans) cout << x << endl;
 
    return 0;
}
 
//maldito talento