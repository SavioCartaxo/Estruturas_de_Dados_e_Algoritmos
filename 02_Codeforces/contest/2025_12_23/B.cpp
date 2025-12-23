//23/12/2025

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i++)
#define endl '\n'
#define ll long long
#define vi vector<ll>
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define MAX 200'000
#define readll(x) ll x; cin >> x;
#define print(x) cout << x << endl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    readll(t);

    while (t--) {
        readll(n);

        vi v(n);
        rep(i,0,n) 
            cin >> v[i];

        vi dif(n);
        ll soma = 0;

        rep(i,0,n) {
            if (i == n-1){
                dif[i] = 0;
            } else {
                dif[i] = abs(v[i] - v[i+1]);
            }

            soma += dif[i];
        }

        ll menor = soma;
        rep(i,0,n) {
            ll somacp = soma;

            if (i == 0) {
                somacp -= dif[i];

            } else if (i == n-1) {
                somacp -= dif[i-1];
            
            } else {
                somacp -= dif[i];
                somacp -= dif[i-1];
                somacp += abs(v[i-1] - v[i+1]);
            }

            menor = min(menor, somacp);
        }

        print(menor);
    }

    return 0;
}