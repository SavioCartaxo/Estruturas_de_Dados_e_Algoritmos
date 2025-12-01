#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;

    vector<bool> valido((int) s.size(), false);
    stack<ll> abre;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '(') {
            abre.push(i);
        } else if (!abre.empty()) {
            valido[i] = true;
            valido[abre.top()] = true;
            abre.pop();
        }
    }

    ll sequenciaAtual = 0, maiorSequencia = 0, quantidade = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (valido[i]) {
            sequenciaAtual++;
        }  else {
            sequenciaAtual = 0;
        }

        if (sequenciaAtual > maiorSequencia) {
            maiorSequencia = sequenciaAtual;
            quantidade = 1;
        } else if (sequenciaAtual == maiorSequencia) {
            quantidade++;
        }
    }

    if (maiorSequencia == 0)
        cout << "0 1" << endl;
    else
        cout << maiorSequencia << ' ' << quantidade << "\n";

    return 0;
}