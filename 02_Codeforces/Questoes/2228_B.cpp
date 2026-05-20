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

void solved() {
    int n, x1 ,x2, k; 
    cin >> n >> x1 >> x2 >> k;

    if (n <= 3) {
        print(1)
        return;
    }

    int Min, Max;
    if (x1 < x2) {
        Min = x1; 
        Max = x2;
    }
    else {
        Min = x2; 
        Max = x1;
    }
    
    int distancia_direita = Max - Min;
    int distancia_esquerda = Min + n-Max;
    int distancia = min(distancia_direita, distancia_esquerda);

    print(distancia + k);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    readint(t)
    while (t--) {
        solved();
    }
    return 0;
}