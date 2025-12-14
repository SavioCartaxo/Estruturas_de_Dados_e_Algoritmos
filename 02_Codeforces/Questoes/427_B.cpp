//14/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, t, c;
    cin >> n >> t >> c;

    stack<bool> st;
    ll a;
    for(ll i = 1; i <= n; i++) {
        cin >> a;
        if (a <= t) st.push(true);
        else st.push(false);
    }

    ll aux = 0;
    ll saida = 0;
    while (!st.empty()) {
        bool continuaSequencia = st.top();
        st.pop();

        if(continuaSequencia) {
            aux++;
        } else {
            if (aux >= c) {
                saida += aux - c + 1;
            }
            aux = 0;
        }
    }

    if (aux >= c)
        saida += aux - c + 1;

    cout << saida << "\n";

    return 0;
}