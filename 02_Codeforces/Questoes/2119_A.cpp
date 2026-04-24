#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define vll vector<vl>

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
        int a, b, x, y; 
        cin >> a >> b >> x >> y;

        if (a > b && (a ^ 1) > b) {
            print(-1)

        } else {            
            int out = 0;

            if (a > b) {
                a = (a ^ 1);
                out = y;
            }
            
            if (x < y) {
                out += (b - a) * x;
            
            } else {

                if ((b - a) & 1) {
                    if (a & 1) 
                        out += x;
                    else
                        out += y;
                    
                    a++;
                }
                
                out += ((b - a) / 2) * y + ((b - a) / 2) * x;
            }

            print(out);
        }
    }
    return 0;
}