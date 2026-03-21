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

    vl v;

    ll aux = 1;
    ll soma = 0;
    while (aux <= 10e9) {
        soma += aux;
        aux *= 2;
        v.pb(soma);
    }

    while (t--) {
        readll(n)

        int i = 1;
        int ans = 1;
        while (i < (int) v.size()) {
            if (n % v[i] == 0) {
                ans = n / v[i];
                break;
            }
            i++;
        }

        print(ans)
    }
    return 0;
}