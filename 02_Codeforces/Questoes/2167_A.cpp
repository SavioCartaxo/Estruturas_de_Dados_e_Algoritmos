// 10/12/2025

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, a, b, c, d;
    cin >> t;

    while (t--){
        cin >> a >> b >> c >> d;

        vi v = {a , b, c, d};
        sort(v.begin(), v.end());

        if (v[0] == v[3]) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}