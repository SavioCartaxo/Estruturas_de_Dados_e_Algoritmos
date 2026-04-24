#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define vll vector<vl>

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
    readint(t)
    while (t--) {
        ll x, y; cin >> x >> y;

        if (x > y || (x == 0 && !(y & 1))) {
            NO
        }
        else {
            YES
            int linha = x + y - 1;
            int pares = x;
            int impares = y;
            int aux = 1;
            bool soma_par = false;
            bool comeco_impar = false;

            if (((x + y) & 1)) impares--;
            else pares--;

            while (linha--) {
                
                if (pares > 0){
                    cout << aux++ << ' ' << aux << endl;
                    
                    if (soma_par)
                        pares--;
                    
                    soma_par = !soma_par;

                } else {
                    if (aux == 1 || !comeco_impar) {
                        aux++;
                        comeco_impar = true;
                    }
                    cout << 1 << ' ' << aux++ << endl;                   
                }
            }
        }
    }
    return 0;
}