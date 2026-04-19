#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define MOD 1000000007

int powm(int a, int b) {
    if (b == 0) return 1;
    if (b % 2) return (powm(a, b - 1) * a) % MOD;
    int res = powm(a, b / 2);
    return (res * res) % MOD;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int N, M, a, b; cin >> N >> M;
    vector<vector<int>> edges(N, vector<int>(N, 0)), crossing1((1LL << N), vector<int>(N, 0));
    for (int i = 0; i < M; i++) {
        cin >> a >> b; a--, b--;
        edges[a][b] = 1;
    }
    for (int i = 0; i < (1LL << N); i++) for (int j = 0; j < N; j++) if (i & (1LL << j)) for (int k = 0; k < N; k++) if (edges[k][j]) crossing1[i][k]++;
    vector<int> dp((1LL << N), 1);
    for (int i = 0; i < (1LL << N); i++) {
        if ((bool)(i & 1) + (bool)(i & 2) == 1) {
            dp[i] = 0;
            continue;
        }
        vector<int> idxs;
        for (int j = 0; j < N; j++) if (i & (1LL << j)) idxs.push_back(j);
        for (int j = 1; j < (1LL << (int)idxs.size()) - 1; j++) {
            int _i = 0, __i = 0, crntv = 1;
            for (int k = 0; k < idxs.size(); k++) {
                if (j & (1LL << k)) _i += (1LL << idxs[k]);
                else __i += (1LL << idxs[k]);
            }
            for (int k = 0; k < N; k++) if (_i & (1LL << k)) crntv *= powm(2, crossing1[__i][k]) - 1 + MOD, crntv %= MOD;
            for (int k = 0; k < N; k++) if (__i & (1LL << k)) crntv *= powm(2, crossing1[_i][k]), crntv %= MOD;
            dp[i] += (dp[_i] * crntv) % MOD;
            dp[i] %= MOD;
        }
    }
    cout << (powm(2, M) - dp.back() + MOD * 2) % MOD << '\n';
}
