//22/12/2025

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
        readll(a);
        readll(b);
    
        if (a == b) {
            print(0)
        }
        else {
            
            // transforma todos os bits de A em 1 (aqui, é so nao contar o primeiro bit 1 que da certo)
            bool primeiro1 = false;
            ll primeiroXor = 0;
            for (ll i = 32; i >= 0; i--) {
                if (a & (1LL << i)) { // se o bit a[i] == 1
                    primeiro1 = true;
                } else {
                    if (primeiro1) {
                        primeiroXor = primeiroXor + (1LL << i);
                    }
                }
            }

            a = a ^ primeiroXor;

            if (b > a){
                print(-1)
                continue;
                }

            // para cada bit, verfica de o bit é == 0 em b, se for, adiciona no xor
            primeiro1 = false;
            ll SegundoXor = 0;
            for (ll i = 32; i >= 0; i--) {
                if (a & (1LL << i)) { // se o bit a[i] == 1
                    primeiro1 = true;
                }
                
                if (primeiro1) {
                    if (  !(  b & (1LL << i)  )  ) { // se o bit b[i] == 0
                        SegundoXor = SegundoXor + (1LL << i);
                    }
                }
            }

            // assim, eu sempre preciso de apenas 2 xor para fazer a transformação
            print(2)
            cout << primeiroXor << ' ' << SegundoXor << endl;
        }
    }

    return 0;
}