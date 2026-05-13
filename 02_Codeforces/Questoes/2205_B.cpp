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

vector<bool> crivo() {
    int MAX = sqrt(1e9);
    vector<bool> vb(MAX+1, true);

    vb[0] = vb[1] = false;

    for (int i = 2; i*i <= MAX; i++) {
        if (vb[i]) {
            for (int j = i*i; j < MAX+1; j+=i) {
                vb[j] = false;
            }
        }
    }
    return vb;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    readint(t)
    while (t--) {
        ll n; cin >> n;

        ll aux = 1;
        vector<bool> vb = crivo();

        for (int i = 2; i < (int) vb.size(); i++) {
            if (vb[i]) {
                ll primo = i;
                
                if (n % primo == 0) {
                    while (n % primo == 0) {
                        n /= primo;
                    }
                    aux *= primo;
                }
            }
        }

        aux *= n;

        print(aux)
        }
    return 0;
}