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

#define MOD 1000000007

bool ehFirmeza(ll n, int a, int b) {
    string s = to_string(n);
    for (char c : s) {
        if (c != '0' + a && c != '0' + b) {
            return false;
        }
    }
    return true;
}

ll fact(ll n) {
    ll saida = 1;
    rep (i, 2, n+1) {
        saida = (saida * i) % MOD;
    }
    return saida;
}

ll power(ll base, ll exp) {
    ll result = 1;
    base %= MOD;

    while (exp > 0) {
        if (exp & 1) { 
            result = result * base % MOD;
        }
        base = base * base % MOD;
        exp /= 2;
    }
    return result % MOD;
}

ll inv(ll a) {
    return power(a, MOD - 2); 
}

int main() {
    readll(a) readll(b) readll(n)
    
    ll saida = 0;
    rep (i, 0, n+1) {
        if (ehFirmeza(a * (n-i) + b * i, a, b)) {
            saida = (saida + ((fact(n) * inv(fact(n-i))) % MOD * inv(fact(i)) % MOD)) % MOD;
        }
    }

    print(saida)

    return 0;
}