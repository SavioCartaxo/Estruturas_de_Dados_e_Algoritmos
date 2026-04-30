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
        readint(n) readint(k)

        vi v(n+1, 0), v2(n+1, 0);
        map<int, int> m;

        rep (i, 1, n+1) {
            cin >> v[i];
            m[v[i]] = i;
        }

        bool yes = true;
        map<int, int> aux;
        rep (i, 1, n+1) {
            cin >> v2[i];
            aux[v2[i]]++;
            if (aux[v2[i]] > 1 && v2[i] != -1)
                yes = false;
        }

        if (!yes) {
            NO
            continue;
        }

        rep (i, 1, n+1) {
            if (v2[i] != -1) {

                if (
                v2[i] == v[i] || 
                v2[i] >= n-k+1 && v2[i] <= k

                ) {
                    continue;
                } else {
                    yes = false;
                    break;
                }
                
            }
        }

        if (yes) YES
        else NO
    }
    return 0;
}