#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
    for (int i = 0; i <= N; i++) {
        if (B - A >= i * (C + D) - (N - 1) * D && B - A <= i * (C + D) - (N - 1) * C) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}
