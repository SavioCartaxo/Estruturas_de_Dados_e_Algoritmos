// 08/01/2026

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool found = false;

        long long first_even = -1;
        for (long long x : a) {
            if (x % 2 == 0) {
                if (first_even == -1) {
                    first_even = x;
                } else {
                    cout << first_even << " " << x << "\n";
                    found = true;
                    break;
                }
            }
        }

        if (found) continue;

        for (int i = 0; i < n && !found; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[j] % a[i] == 0) {
                    cout << a[i] << " " << a[j] << "\n";
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            cout << -1 << "\n";
        }
    }

    return 0;
}
