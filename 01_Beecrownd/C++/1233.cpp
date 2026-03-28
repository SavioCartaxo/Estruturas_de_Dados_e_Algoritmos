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

ll funcaoFiDeEuler(ll n) {
    ll ens = n;
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            while (n%i == 0) n /= i;
            ens -= ens/i;
        }
    }

    if (n > 1) ens -= ens/n;
    return ens;
}

int main() {
    ll a;
    while(cin >> a) {
        print(funcaoFiDeEuler(a) / 2)
    }
    return 0;
}