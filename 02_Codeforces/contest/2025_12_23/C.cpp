//23/12/2025

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i++)
#define endl '\n'
#define ll long long
#define vi vector<ll>
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define MAX 200'000
#define readll(x) ll x; cin >> x;
#define print(x) cout << x << endl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    readll(t);

    while (t--) {
        readll(n);

        vi v(n);
        rep(i,0,n) 
            cin >> v[i];

        ll menor = *min_element(all(v));
        

        bool aux = true;
        rep(i ,0, n) {
            if (v[i] / 2.0 <= menor && v[i] != menor) {
                aux = false;
                break;
            }
        }

        ll segundoMenor = 1'000'000'000;
        rep(i,0,n) {
            if (v[i] != menor) {
                segundoMenor = min(segundoMenor, v[i]);
            }
        }

        if (aux) print(segundoMenor - menor)
        else print(menor)


    }

    return 0;
}