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

#define endl "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define rep(i,a,b) for (int i = a; i < b; i++)

#define print(x) cout << x << endl;

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

int binpow(int a, int b) {
    int out = 1;
    while (b) {
        if (b & 1) out *= a;
        a *= a;
        b >>= 1;
    }
    return out;
}

void printv(priority_queue<int> v) {
    while (!v.empty()) {
        cout << v.top();
        v.pop();

        if (!v.empty()) {
            cout << ' ';
        }
    }
    cout << endl;
}

ll maior_base(ll n) {
    ll mb = 63 - __builtin_clzll(n);
    return binpow(2, mb);
}

void solved() {
    ll n, k;
    cin >> n >> k;
    
    if (k > n) {
        NO
        return;
    }

    ll numero_minimo = __builtin_popcountll(n);
    if (numero_minimo > k) {
        NO
        return;
    }

    YES

    priority_queue<int> pq;
    for (int i = 31; i >= 0; i--) {
        if (n & (1 << i)) {
            pq.push(binpow(2,i));
        }
    }

    int pode_dividir = 0;
    k = k - numero_minimo;

    while (k--) {
        int numero = pq.top();
        pq.pop();

        pq.push(numero / 2);
        pq.push(numero / 2);
    }

    printv(pq);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solved();
    return 0;
}