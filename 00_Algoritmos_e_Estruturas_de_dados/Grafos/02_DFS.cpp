#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

// DFS base
vector<bool> visitados;
vii grafo;
void recursive_dfs(int raiz) {
    visitados[raiz] = true;

    for (auto vizinho : grafo[raiz]) {
        if (!visitados[vizinho]) {
            recursive_dfs(vizinho);
        }
    }
}

void inline_dfs() {
    // Lista de vizitados já está criada
    // Grafo já está definido

    stack<int> pilha;

    for (int i = 0; i < (int) grafo.size(); i++) {
        if (visitados[i])
            continue;

        visitados[i] = true;
        pilha.push(i);

        while (!pilha.empty()) {
            auto aux = pilha.top();
            pilha.pop();
            
            for (auto vizinho : grafo[aux]) {
                if (!visitados[vizinho]) {
                    pilha.push(vizinho);
                    visitados[vizinho] = true;    
                }
            }
        }
    }
}

int main() {
    return 0;
}