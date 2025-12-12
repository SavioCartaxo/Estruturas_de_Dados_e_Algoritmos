// 11/12/2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    ll n, q;
    string str;
    ll a, j, resposta;
    while (t--) {
        cin >> n >> q >> str;

        bool temB = false;
        for(int i = 0; i < (int) str.size(); i++) {
            if (str[i] == 'B') {
                temB = true;
                break;
            }
        }

        for (int i = 0; i < q; i++) {
            cin >> a;

            if (!temB) {
                cout << a << endl;
            }
            else{
                j = 0;
                resposta = 0;
                while (a >= 1) {
                    j = (j%n);

                    if (str[j] == 'A') 
                        a -= 1;
                    else 
                        a = a / 2;
                    
                    resposta++;
                    j++;
                }

                cout << resposta << "\n";
            }
        }
    }

    return 0;
}