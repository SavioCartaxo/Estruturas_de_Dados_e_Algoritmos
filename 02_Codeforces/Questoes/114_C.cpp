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
#define sz(x) (int)x.size()
#define rep(i,a,b) for (int i = a; i < b; i++)

#define print(x) cout << x << endl;

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

pair<bool, bool> ehadjetivo(string &s) {
    ll tamanho = sz(s);
    bool a = tamanho >= 4 && s.substr(tamanho - 4, 4) == "lios";
    bool b = tamanho >= 5 && s.substr(tamanho - 5, 5) == "liala";
    bool masculino = a;
    return {a || b, a};
}

pair<bool, bool> ehsubstantivo(string &s) {
    ll tamanho = sz(s);
    bool a = tamanho >= 3 && s.substr(tamanho - 3, 3) == "etr";
    bool b = tamanho >= 4 && s.substr(tamanho - 4, 4) == "etra";
    return {a || b, a};
}

pair<bool, bool> ehverbo(string &s) {
    ll tamanho = sz(s);
    bool a = tamanho >= 6 && s.substr(tamanho - 6, 6) == "initis";
    bool b = tamanho >= 6 && s.substr(tamanho - 6, 6) == "inites";
    return {a || b, a};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string s;
    vector<string> vs;
    bool adjetivo = false;
    bool substantivo = false;
    bool verbo = false;
    bool masculino;

    ll tamanho = 0;
    while (cin >> s) {
        vs.pb(s);
        tamanho++;
    }

    if (tamanho == 1) {
        if (ehadjetivo(s).first || ehsubstantivo(s).first || ehverbo(s).first) {
            YES
        } else
            NO
        return 0;
    }

    s = vs[0];

    if (ehadjetivo(s).first)
        masculino = ehadjetivo(s).second;

    else if (ehsubstantivo(s).first)
        masculino = ehsubstantivo(s).second;

    else if (ehverbo(s).first)
        masculino = ehverbo(s).second;

    else {
        NO
        return 0;
    }

    for (int i = 0; i < sz(vs); i++) {
        s = vs[i];
        if (ehadjetivo(s).first && ehadjetivo(s).second == masculino && substantivo == false && verbo == false) {
            adjetivo= true;
        }  else if (ehsubstantivo(s).first && ehsubstantivo(s).second == masculino && verbo == false && !substantivo) {
            substantivo = true;
            adjetivo= true;
        } else if (ehverbo(s).first && ehverbo(s).second == masculino && substantivo && adjetivo) {
            verbo = true;
        } else {
            NO
            return 0;
        }
    }

    if (!substantivo) {
        NO
        return 0;
    }

    YES

    return 0;
}