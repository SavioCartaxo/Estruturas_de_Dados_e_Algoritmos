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

#define endl "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define rep(i,a,b) for (int i = a; i < b; i++)

#define print(x) cout << x << endl;

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solved() {
    string s;
    cin >> s;

    int y = 0;
    int n = 0;

    for (char c : s) {
        if (c == 'Y') y++;
        else n++;
    }

    if (y > 1)
        NO
    else
        YES
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    readint(t)
    while (t--) {
        solved();
    }
    return 0;
}