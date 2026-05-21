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
 
#define MOD 1000000009LL
 
ll binpow(ll a, ll b) {
    a = a % MOD;
    ll out = 1;
    while (b) {
        if (b & 1) 
            out = (out * a) % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return out % MOD;
}
 
int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    
    ll soma = (n / k) * (k - 1);
    soma += n % k;
    if (soma >= m) {
        print(m)
        return 0;
    }
 
    ll sequencias_seguidas = m - soma;
    ll aux = binpow(2, sequencias_seguidas+1);
    ll out = ((aux - 2 + MOD) % MOD* k) % MOD;
    out = (out + m - (sequencias_seguidas * k) + MOD) % MOD;
    print(out)
 
    return 0;
}