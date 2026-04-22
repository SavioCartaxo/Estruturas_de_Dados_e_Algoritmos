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
        readint(n) readint(k)

        vl v(n);
        for (auto &i: v) {cin >> i;}

        readint(posicao)
        int valor = v[posicao-1];
        int left = posicao - 2, right = posicao;

        int conta_bloco_dif_left = 0;
        bool bloco_dif_left = false;

        while (left >= 0) {
            if (v[left] != valor) {
                if (bloco_dif_left == false) conta_bloco_dif_left++;
                bloco_dif_left = true;
            }
            else {
                bloco_dif_left = false;
            }
            left--;
        }

        int conta_bloco_dif_right = 0;
        bool bloco_dif_right = false;
        while (right < n) {
            if (v[right] != valor) {
                if (bloco_dif_right == false) conta_bloco_dif_right++;
                bloco_dif_right = true;
            }
            else {
                bloco_dif_right = false;
            }
            right++;
        }

        print(max(conta_bloco_dif_left, conta_bloco_dif_right) * 2)
    }
    return 0;
}