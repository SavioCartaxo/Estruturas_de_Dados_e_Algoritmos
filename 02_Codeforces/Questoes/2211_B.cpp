#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define vll vector<vl>
#define vi vector<int>
#define vii vector<vi>

#define readll(x) ll x; cin >> x;
#define readint(x) int x; cin >> x;
#define reads(x) string x; cin >> x;
#define readc(x) char x; cin >> x;

#define endl "\n"
#define pb push_back

#define rep(i,a,b) for (int i = a; i < b; i++)
#define rep4(i,a,b,c) for (int i = a; i < b; i+=c)
#define repneg(i,a,b) for (int i = a; i > b; i--)
#define repneg4(i,a,b,c) for (int i = a; i > b; i-=c)

#define print(x) cout << x << endl;

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

int main() {
    readint(t)
    while (t--) {
        int x, y; cin >> x >> y;
        int dif = abs(x - y);
        int out = 0;
        if (x == y)
            cout << 1 << endl;
        else{
            for (int i = 1; i < dif + 1; i++) {
                if (dif % i == 0) {
                    out++;
                }
            }

            cout << out << endl;
        }

        bool espaco = false;
        if (x > 0 && y > 0) {
            espaco = true;
        }

        while (x--) {
            cout << 1;
            if (x - 1 >= 0) {
                cout << ' ';
            }
        }

        if (espaco) {cout << ' ';}

        while (y--) {
            cout << -1;
            if (y - 1 >= 0) {
                cout << ' ';
            }
        }

        cout << endl;
    }
    return 0;
}