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
 
ll meu_pow(ll base, ll expoente) {
    ll result = 1;
    while (expoente--) {
        result *= base;
    }
    return result;
}
 
ll monta_numero(vector<bool> &vb) {
    ll aux = 0;
    for (ll i = 62; i >= 0; i--) {
        if (vb[i]) {
            aux += meu_pow(2, 62 - i);
        }
    }
    return aux;
}
 
int main() {
    readll(n)
    ll aux = n;
    vector<bool> vb(63);
    ll primeiro_1 = 0;
 
    for (ll i = 62; i >= 0 && aux != 0; i--) {
        if (aux - meu_pow(2, i) >= 0) {
            if (primeiro_1 == 0) {
                primeiro_1 = 62 - i;
            }
        }
    }
 
    ll r = primeiro_1, l = 62;
    while (r <= l) {
        vb[r] = true;
        vb[l] = true;
 
        if (n < monta_numero(vb)) {
            
            if (r == primeiro_1) {
                print(n-1)
                return 0;
            }

            vb[r] = false;
            vb[l] = false;
        }
 
        r++; l--;
    }
 
    aux = monta_numero(vb);
    print(aux)
 
    return 0;
}
 
// Salvio ou Sarvio?