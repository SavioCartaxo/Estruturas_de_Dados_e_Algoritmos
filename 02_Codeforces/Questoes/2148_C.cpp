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

    ll n, m, a, b;
    while (t--) {
        cin >> n >> m;
        ll saida = m;

        priority_queue<pair<ll,ll>> pq;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            pq.push({-a, b});
        }

        bool precisaMesmaPartidade = true;
        while (!pq.empty()) {

            auto p = pq.top(); pq.pop();
            ll minuto = -(p.first); // minuto X
            ll pos = p.second;   // tem que estar na pos(0 ou 1)
            
            if (precisaMesmaPartidade){
                
                if (((minuto & 1) != pos)) {
                    saida--;
                    precisaMesmaPartidade = !precisaMesmaPartidade;
                }

            } else {
                
                if (((minuto & 1) == pos)) {
                    saida--;
                    precisaMesmaPartidade = !precisaMesmaPartidade;
                }
            }
            
        }

        cout << saida << "\n";
    }

    return 0;
}