#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vb vector<bool>
#define pb push_back

const int MAX = 1'000'000;

// Crivo linear que acha os primos até n
vb crivo() {
    vb primo(MAX+1, true);
    primo[0] = primo[1] = false;

    for (int i = 2; (1LL*i*i) <= MAX; i++) {
        if (primo[i]) {
            for (int j = i*i; j <= MAX; j+=i) {
                primo[j] = false;
            }
        }
    }

    return primo;
}

vi medo() {
    vb primo = crivo();
    vi saida(MAX + 1);
    int soma = 0;

    for (int i = 0; i <= MAX; i++) {
        
        if (!primo[i]) {
            saida[i] = soma; 
            continue;
        }
        
        string s = to_string(i);

        bool temZero = false;
        for (char c : s) {
            if (c == '0') {
                temZero = true; // adoram todos primos que tem 0
                break;
            }
        }

        if (temZero) {
            saida[i] = soma;
            continue;
        }

        bool medo = true;
        while (!s.empty()) {
            if (!primo[stoi(s)]) {
                medo = false;
                break;
            }
            s.erase(s.begin());
        }

        if (medo) {
            saida[i] = ++soma;
        } else {
            saida[i] = soma;
        }
    }

    return saida;
}

int main() {
    int t, n;
    cin >> t;

    vb vs = crivo();

    while (t--) {
        cin >> n;
        cout << vs[n] << endl;
    }

    return 0;
}