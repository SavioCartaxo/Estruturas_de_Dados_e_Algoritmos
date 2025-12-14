//14/12/2025

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m; cin >> m;

    string velho, novo;
    map<string, vector<string>> dict;
    set<string> s;

    int saida = 0;
    while(m--) {
        cin >> velho >> novo;

        if (s.count(novo)) continue;

        string ondeAdicionar = "FLAG";
        for (auto usuario : dict) {
            if (usuario.second[((int)usuario.second.size()) - 1] == velho)
                ondeAdicionar = usuario.first;
        }

        if (ondeAdicionar == "FLAG") {
            dict[velho] = {velho, novo};
            saida++;
        } else {
            dict[ondeAdicionar].push_back(novo);
        }

        s.insert(velho);
        s.insert(novo);

    }

    cout << saida << endl;
    for (auto usuario : dict) {
        cout << usuario.first << ' ' << usuario.second[((int)usuario.second.size()) - 1] << "\n";
    }

    return 0;
}