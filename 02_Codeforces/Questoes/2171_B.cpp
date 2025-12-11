// 10/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    ll n;
    while (t--) {
        cin >> n;

        vi v(n);
        ll soma = 0;
        ll a;
        bool first = false;
        bool last = false;

        for (int i = 0; i < n; i++){
            cin >> a;
            
            if (a == -1) {
                v[i] = 0;
                if (i == 0) {first = true;}
                if (i == n-1) {last = true;}} 
            
            else 
            {v[i] = a;}

            if (i > 0) 
            {soma += v[i] - v[i-1];}
        }

        ll saida = abs(soma);

        if (soma > 0 && first) {    
            v[0] = saida;
            saida = 0;
        }

        if (soma < 0 && last) {
            v[n-1] = saida;
            saida = 0;
        }
        
        cout << saida << "\n";
        cout << v[0];
        for (int i = 1; i < n; i++) {
            cout << ' ' << v[i];
        }
        cout << "\n";
    }

    return 0;
}