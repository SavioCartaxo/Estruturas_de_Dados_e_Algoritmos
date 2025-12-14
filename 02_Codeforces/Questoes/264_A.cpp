//14/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    vi v;
    for (int i = 0; i < (int) s.size(); i++) {
        
        if (s[i] == 'r') {
            cout << i+1 << "\n";
        } else {
            v.push_back(i+1);
        }
    }

    for (int i = (int) v.size() - 1; i >= 0; i--)
        cout << v[i] << "\n";
    
    return 0;
}