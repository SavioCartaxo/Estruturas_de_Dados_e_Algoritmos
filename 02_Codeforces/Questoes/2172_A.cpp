// 10/12/2025

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    vi v = {a , b, c};
    sort(v.begin(), v.end());

    if (v[2] - v[0] >= 10) {
        cout << "check again" << "\n";
    } else {
        cout << "final " << v[1] << "\n";
    }

    return 0;
}