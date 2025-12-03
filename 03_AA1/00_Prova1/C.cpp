#include <bits/stdc++.h>
using namespace std;

#define d double
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll a;
    while (n--) {
        cin >> a;

        bool foi = false;
        while (a > 2) {
            // se A é impar
            if (a % 2 == 1) {
                cout << "YES" << endl;
                foi = true;
                break;
            // se A é par
            } else {
                a = a / 2;
            }
        }

        if (!foi) {cout << "NO" << endl;}
    }

    return 0;
}