// 11/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    ll n, x, y;
    while (t--) {
        cin >> n >> x >> y;

        x = abs(x);
        y = abs(y);

        string s;
        cin >> s;
        
        ll c4 = 0;
        ll c8 = 0;
        for (char c : s) {
            if (c == '4')
                c4++;
            else
                c8++;
        }

        ll menor = min(x,y);
        ll maior = max(x,y);

        string saida = "NO\n";
        if (menor <= c8) {
            c8 -= menor;
            maior -= menor;
            
            if (c8 + c4 >= maior) {
                saida = "YES\n";
            }
        
        } else {
            menor -= c8;
            maior -= c8;
            ll somaBlocosFalta = menor + maior;

            if (c4 >= somaBlocosFalta) {
                saida = "YES\n";
            }
        }
        
        cout << saida;
    }

    return 0;
}