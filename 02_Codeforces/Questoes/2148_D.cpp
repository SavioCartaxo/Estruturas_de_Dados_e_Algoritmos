//14/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    ll n, a;
    while (t--) {
        cin >> n;

        vi impar;
        ll saida = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            if (a & 1)
                impar.pb(a);
            else
                saida+=a;
        }

        if (impar.empty())
            saida = 0;
        else {
            sort(impar.begin(), impar.end());
            for (int i = ((int)impar.size())/2; i < (int)impar.size(); i++) 
                saida += impar[i];
        }

        cout << saida << "\n";
    }

    return 0;
}