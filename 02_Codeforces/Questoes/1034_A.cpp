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

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);

    while (b != 0) {
        ll aux = a;
        a = b;
        b = aux % b;
    }

    return a;
}

#define MAX 15000000
vector<int> crivo() {
    vector<int> v = {2};
    vector<bool> vb(MAX+1, true);

    vb[0] = vb[1] = false;

    for (int i = 3; i*i <= MAX; i+=2) {
        if (vb[i]) {
            int aux = i*2;
            while (aux <= MAX) {
                vb[aux] = false;
                aux += i;
            }
        }
    }

    for (int i = 3; i <= MAX; i+=2) {
        if (vb[i]) v.pb(i);
    }

    return v;
}

int main() {
    ll n; cin >> n;
    vl v(n);

    ll mdc = 0;

    for (auto &i : v) {
        cin >> i;
        mdc = gcd(mdc, i);
    }

    for (auto &i : v) i /= mdc;

    map<ll,ll> m;
    auto p = crivo();

    for (auto &i : v) {
        int j = 0;
        while(p[j] <= i) {
            ll aux = p[j];
            if (i % aux == 0) 
                m[aux]++;
            
            while (i % aux == 0) {
                i /= aux;
            }
            j++;
        }
    }

    ll maior = 0;
    for (auto &[key, value] : m) {
        maior = max(maior, value);
    }

    ll saida = n - maior;

    if (maior == 0)
        saida = -1;

    print(saida)

    return 0;
}