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
#define repneg(i,a,b) for (int i = a; i > b; i--)
 
#define print(x) cout << x << endl;
 
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
 
void pass() {
 
}
 
void solved() {
    readint(n)
 
    reads(str1)
    reads(str2)
 
    vector<string> vs = {str1, str2};
    vector<vector<bool>> vb(2, vector<bool>(n));
    vector<pair<int, int>> movimentos = {{-1, 0}, // Esquerda
                                        {1,  0}, // Direita
                                        {0,  1}, // Baixo
                                        {0, -1}  // Cima
    };
    stack<pair<int, int>> pilha; // vertical(linha) / horizontal(coluna)
    pilha.push({0,0});
 
    while (!pilha.empty()) {
        auto posicao = pilha.top(); pilha.pop();
        auto posicao_horizontal = posicao.second;
        auto posicao_vertical = posicao.first;
 
        if (vb[posicao_vertical][posicao_horizontal]) {
            continue;
        }
 
        vb[posicao_vertical][posicao_horizontal] = true;
 
        if (vb[1][n-1]) {
            YES
            return;
        }
 
        for (auto movimento : movimentos) {
            auto horizontal = movimento.second;
            auto vertical   = movimento.first;
 
            auto ph = posicao_horizontal;
            auto pv = posicao_vertical;
 
            ph += horizontal;
            pv += vertical;
 
            if (ph < 0 || ph >= n || (pv != 0 && pv != 1)) {
                continue;
            }
 
            // marcar como visitado
            vb[pv][ph] = true;
            
            // movimenta
            if (vs[pv][ph] == '<') {
                ph--;
 
                if (ph < 0) {
                    ph++;
                }
 
            } else { // == >
                ph++;
                
                if (ph >= n) {
                    ph--;
                }
            }
 
            // adicionar a pilha
            pilha.push({pv, ph});
        }
    }
 
    NO
}
 
int main() {
    readint(t)
    while(t--) {
        solved();
    }
    return 0;
}