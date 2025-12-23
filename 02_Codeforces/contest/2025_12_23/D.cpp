//23/12/2025

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < b; i++)
#define reprev(i,a,b) for(ll i = a; i >= b; i--)
#define endl '\n'
#define ll long long
#define vi vector<ll>
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define readll(x) ll x; cin >> x;
#define print(x) cout << x << endl;
#define MAX 1'000'000'000
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    readll(t);

    while (t--) {
        readll(n);
        n = pow(2,n);

        vector<bool> vb(n,false);
        vi v(n);
        ll pos = 0;

        for (ll i = n-1; i >= 0; i--) { 
            if (!vb[i]){
                vb[i] = true;

                ll aux = __builtin_popcountll(i);
                
                v[pos++] = i;
                
                for(ll j = i-1; j > -1; j--) {
                    
                    if (!vb[j]){
                        ll auxb = __builtin_popcountll(j & i);
                        
                        if (auxb == aux) {
                            v[pos++] = j;
                            vb[j] = true;
                        }
                    }

                }
            }
        }

        cout << v[0];
        rep(i,1,n) cout << ' ' << v[i];
        cout << endl;
    }

    return 0;
}