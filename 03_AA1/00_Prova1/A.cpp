#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll q, n;
    cin >> q;

    while(q--) {
        cin >> n;
        string s1 = "", s2="";

        char c;
        for (int i = 0; i < n; i++) {
            cin >> c;
            s1.push_back(c);
        }

        for (int i = 0; i < n; i++) {
            cin >> c;
            s2.push_back(c);
        }

        vector<bool> vb(n, false);
        vector<bool> vj(n,false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s1[i] == s2[j] && !vb[i] && !vj[j]) {
                    vb[i] = true;
                    vj[j] = true;
                }
            }
        }

        bool temF = false;
        for (int i = 0; i < n; i++) {
            if (vb[i] == false) {
                temF = true;
                break;
            }
        }

        if (!temF) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}