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

int f(string &x) {
    int soma = 0;
    for (char c : x) {
        soma += c - '0';
    }
    return soma;
}

int solved(string &x) {
    int n = x.size();
    int soma = f(x);
    
    if (soma <= 9) return 0;
    
    vl d;
    d.pb(x[0] - '0' - 1);
    rep(i, 1, n) d.pb(x[i] - '0');
    
    sort(d.begin(), d.end(), greater<ll>());
    
    int k = 0;
    rep(i, 0, (int)d.size()) {
        soma -= d[i];
        k++;
        if (soma <= 9) return k;
    }
    
    return k;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    readint(t)
    while (t--) {
        string x; cin >> x;
        print(solved(x))
    }
    return 0;
}