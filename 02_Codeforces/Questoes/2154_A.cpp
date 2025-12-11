// 10/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    ll n, k;
    while (t--) {
        cin >> n >> k;
        
        string str;
        cin >> str;
        ll c = k, s = 0;
        for (int i = 0; i < n; i++) {
            if (str[i] == '0') {
                c++;
            } else {
                if (c >= k - 1) {
                    s++;
                }
                c = 0;
            }
        }

        cout << s << endl;
    }

    return 0;
}