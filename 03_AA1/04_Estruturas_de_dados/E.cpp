#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vi vector<ll>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vi v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }

    vi s(n);
    stack<ll> st; // guarda índices

    for (ll i = 0; i < n; i++) {
        
        while(!(st.empty()) && v[st.top()] >= v[i]) {
            st.pop();
        }

        if (st.empty()) s[i] = 0;
        else {s[i] = st.top() + 1;}

        st.push(i);
    }

    for (ll i = 0; i < n; i++) {
        cout << s[i] << " ";
    }
}
