#pragma GCC optimize("O3,inline")
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define int long long

#define MOD 998244353

int powm(int a, int b) {
    if (b == 0) return 1;
    if (b % 2) return (a * powm(a, b - 1)) % MOD;
    int res = powm(a, b / 2);
    return (res * res) % MOD;
}

vector<int> mem1, mem2;

int invm(int a) {
    return powm(a, MOD - 2);
}

int fact(int a) {
    if (mem1[a] != -1) return mem1[a];
    return mem1[a] = (a * fact(a - 1)) % MOD;
}

int ifact(int a) {
    if (mem2[a] != -1) return mem2[a];
    return mem2[a] = invm(fact(a));
}

int choose(int a, int b) {
    return (((fact(a) * ifact(b)) % MOD) * ifact(a - b)) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string A, B; cin >> A >> B;
    int a = 0, b = 0;
    for (int i = 0; i < A.size(); i++) a += (A[i] == '1' && B[i] == '0'), b += (A[i] == '1' && B[i] == '1');
    vector<vector<int>> g(a + 1, vector<int>(b + 1, 0));
    mem1.resize(100000, -1);
    mem2.resize(100000, -1);
    mem1[0] = 1, g[0][0] = fact(b);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= j; k++) {
                g[i + 1][j] += (g[i][k] * choose(i + j + 1, i + k)) % MOD;
                g[i + 1][j] %= MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= b; i++) ans += (g[a][i] * ifact(a + i)) % MOD, ans %= MOD;
    cout << (((ans * fact(a)) % MOD) * fact(a + b)) % MOD << '\n';
}
