#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi  vector<ll>
#define MAX 500000

vi crivo() {
    vi v(MAX + 1, 0);
    for (int i = 1; i < MAX; i++) {
        ll n = i+i;
        while (n <= MAX) {
            v[n]+=i;
            n+=i;
        }
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, a; cin >> n;
    vi v = crivo();
    
    while (n--) {
        cin >> a;
        cout << v[a] << "\n";
    }

    return 0;
}