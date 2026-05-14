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

#define rep(i,a,b) for (int i = a; i < b; i++)
#define repneg(i,a,b) for (int i = a; i > b; i--)

#define print(x) cout << x << endl;

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    readint(n)
    map< string, int> deep;
    deep["polycarp"]++;

    while (n--) {
        string filho, _, pai; cin >> filho >> _ >> pai;
        
        transform(pai.begin(), pai.end(), pai.begin(), ::tolower);
        transform(filho.begin(),filho.end(), filho.begin(), ::tolower);

        deep[filho] = deep[pai] + 1;
    }

    ll ans = 0;
    for (auto [name, d] : deep) 
        ans = max(ans, (ll)d);
    
    print(ans)

    return 0;
}