#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vb vector<bool>
#define pb push_back


vb crivo(int n) {
    vb is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; (1LL*i*i) <= n; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= n; j+=i) {
                is_prime[j] = false;
            }
        }
    }

    return is_prime;
}

int main() {
    int n = 1e8;

    vb is_prime = crivo(n);

    int c = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            if (c % 100 == 0)
                cout << i << "\n";
            c++;
        }
    }

    return 0;
}
