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
    if (a < 0 || b < 0) return 0;
    return (((fact(a) * ifact(b)) % MOD) * ifact(a - b)) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mem1.resize(2000000, -1);
    mem2.resize(2000000, -1);
    mem1[0] = 1;
    int N, M; cin >> N >> M;
    if (N > M) swap(N, M);
    int ans = ((M + N) * (choose(M + N - 1, N) + choose(M + N - 1, M))) % MOD;
    for (int i = 0; i < N; i++) {
        ans += ((((M - N + 2 * i) * choose(M - N + 2 * i - 1, i)) % MOD) * choose(2 * N - 2 * i - 1, N - i)) % MOD;
        ans -= ((((M - N + 2 * i + 1) * choose(M - N + 2 * i, i)) % MOD) * choose(2 * N - 2 * i - 2, N - i - 1)) % MOD;
        ans += ((((M - N + 2 * i) * choose(M - N + 2 * i - 1, i - 1)) % MOD) * choose(2 * N - 2 * i - 1, N - i - 1)) % MOD;
        ans -= ((((M - N + 2 * i + 1) * choose(M - N + 2 * i, i)) % MOD) * choose(2 * N - 2 * i - 2, N - i - 1)) % MOD;
    }
    ans %= MOD;
    for (int i = 0; i < N; i++) ans += (choose(M - N + 2 * i, i) * choose(2 * N - 2 * i - 1, N - i)) % MOD;
    ans = (ans + MOD) % MOD;
    cout << (ans * invm(choose(M + N, N))) % MOD << '\n';
}
