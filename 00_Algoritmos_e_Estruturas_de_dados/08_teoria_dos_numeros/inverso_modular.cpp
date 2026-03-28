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

ll power(ll base, ll exp, ll mod) {
    ll saida = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp & 1) {
            saida = saida * base % mod;
        }
        base = base * base % mod;
        exp /= 2;
    }
    return saida;
}

ll inv(ll n, ll m) {
    // quero o inverso modular de n MOD m
    return power(n, m-2, m);
}

int main() {
    
    return 0;
}