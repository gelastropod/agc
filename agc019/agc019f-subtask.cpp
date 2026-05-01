#pragma GCC optimize("O3,inline")
#include <iostream>
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

int invm(int a) {
    return powm(a, MOD - 2);
}

vector<int> mem1, mem2;

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
    mem1.resize(2000000, -1);
    mem2.resize(2000000, -1);
    mem1[0] = 1;
    int N, M; cin >> N >> M;
    int ans = (2 * N * choose(2 * N - 1, N)) % MOD;
    for (int i = 0; i < N; i++) {
        ans += (choose(2 * i, i) * choose(2 * N - 2 * i - 1, N - i)) % MOD;
        ans %= MOD;
    }
    cout << (ans * invm(choose(2 * N, N))) % MOD << '\n';
}
