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
    while(t--) {
        int n, k; cin >> n >> k;

        vector<int> limite_de_capacidade_por_nivel(k);
        for(auto &i : limite_de_capacidade_por_nivel) cin >> i;

        vector<int> nivel_de_desejo(n);
        int c = 0;
        for(auto &i : nivel_de_desejo) {
            cin >> i;
            if (i != k+1) c += (k+1) - i;
        }

        if (c > 1000) print(-1)
        else {
            vector<int> out;
            print(c)
            for (int aux_k = k; aux_k > 0; aux_k--) {
                for (int i = 0; i < n; i++) {
                    if (nivel_de_desejo[i] == aux_k) {
                        int aux = (k - aux_k) + 1;
                        while(aux--) {
                            out.pb(i+1);
                        }
                    }
                }
            }
            if ((int) out.size() > 0)cout << out[0];

            for (int i = 1; i < (int) out.size(); i++) {
                cout << ' ' << out[i];
            }

            cout << endl;
        }
    }
    return 0;
}