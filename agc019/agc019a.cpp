#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int Q, H, S, D, N; cin >> Q >> H >> S >> D >> N;
    int a = min({Q * 4, H * 2, S});
    cout << (N % 2) * a + (N / 2) * min(a * 2, D) << '\n';
}
