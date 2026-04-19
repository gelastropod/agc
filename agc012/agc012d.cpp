#include <bits/stdc++.h>
using namespace std;
#define int long long

#define MOD 1000000007

vector<int> mem;

int fact(int n) {
    if (n <= 1) return 1;
    if (mem[n] != -1) return mem[n];
    return mem[n] = (n * fact(n - 1)) % MOD;
}

int powm(int a, int b) {
    if (b == 0) return 1;
    if (b % 2 == 1) return (a * powm(a, b - 1)) % MOD;
    int res = powm(a, b / 2);
    return (res * res) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, X, Y, a, b, mv = 1e9, mv2 = 1e9, ans = 1, res = 0; cin >> N >> X >> Y;
    vector<vector<int>> vals(N, vector<int>());
    mem.resize(N, -1);
    for (int i = 0; i < N; i++) {
        cin >> a >> b; a--;
        vals[a].push_back(b);
    }
    for (int i = 0; i < N; i++) {
        sort(vals[i].begin(), vals[i].end());
        if (vals[i].size() && vals[i][0] < mv2) mv2 = vals[i][0];
        if (mv2 < mv) swap(mv2, mv);
    }
    for (int i = 0; i < N; i++) {
        if (vals[i].empty()) continue;
        int offs = 0;
        if (vals[i][0] == mv) offs = max(X - mv, Y - mv2);
        else offs = max(X - vals[i][0], Y - mv);
        auto iter = upper_bound(vals[i].begin(), vals[i].end(), offs);
        if ((vals[i][0] == mv && vals[i][0] + mv2 <= Y) || vals[i][0] + mv <= Y) res += iter - vals[i].begin();
        else {
            ans *= fact(iter - vals[i].begin());
            ans %= MOD;
        }
        ans *= powm(fact(iter - vals[i].begin()), MOD - 2);
        ans %= MOD;
    }
    cout << (ans * fact(res)) % MOD << '\n';
}
