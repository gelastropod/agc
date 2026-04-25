#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define MOD 1000000007

int powm(int a, int b) {
    if (b == 0) return 1;
    if (b % 2) return (a * powm(a, b - 1)) % MOD;
    int res = powm(a, b / 2);
    return (res * res) % MOD;
}

int invm(int a) {
    return powm(a, MOD - 2);
}

vector<int> mem, mem1;

int fact(int a) {
    if (mem[a] != -1) return mem[a];
    return mem[a] = (a * fact(a - 1)) % MOD;
}

int fact1(int a) {
    if (mem1[a] != -1) return mem1[a];
    return mem1[a] = invm(fact(a));
}

int choose(int a, int b) {
    return (((fact(a) * fact1(b)) % MOD) * fact1(a - b)) % MOD;
}

int f(int a, int b) {
    return choose(a + b, a);
}

int g(pair<int, int> a, pair<int, int> b) {
    return f(b.first - a.first, b.second - a.second);
}

int h(pair<int, int> a, pair<int, int> b) {
    return (b.first - a.first) + (b.second - a.second) + 1;
}

int calc(pair<int, int> a, pair<int, int> b, pair<int, int> c, int dim) {
    auto modb = b;
    if (dim) modb.second++;
    else modb.first++;
    return (((g(a, b) * g(modb, c)) % MOD) * h(a, b)) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mem.resize(5000000, -1);
    mem[0] = 1;
    mem1.resize(5000000, -1);
    int ans = 0, x1, x2, x3, x4, x5, x6, y1, y2, y3, y4, y5, y6; cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6 >> y1 >> y2 >> y3 >> y4 >> y5 >> y6;
    vector<pair<pair<int, int>, int>> vals1 = { {{x1 - 1, y1 - 1}, 1}, {{x1 - 1, y2}, -1}, {{x2, y1 - 1}, -1}, {{x2, y2}, 1} }, vals2 = { {{x6 + 1, y6 + 1}, 1}, {{x6 + 1, y5}, -1}, {{x5, y6 + 1}, -1}, {{x5, y5}, 1} };
    for (int i = 0; i < 16; i++) {
        auto p1 = vals1[i / 4].first;
        auto p2 = vals2[i % 4].first;
        int val = vals1[i / 4].second * vals2[i % 4].second;
        for (int j = x3; j <= x4; j++) {
            ans -= val * calc(p1, { j, y3 - 1 }, p2, 1);
            ans += val * calc(p1, { j, y4 }, p2, 1);
            ans %= MOD;
        }
        for (int j = y3; j <= y4; j++) {
            ans -= val * calc(p1, { x3 - 1, j }, p2, 0);
            ans += val * calc(p1, { x4, j }, p2, 0);
            ans %= MOD;
        }
    }
    cout << (ans + MOD) % MOD << '\n';
}
