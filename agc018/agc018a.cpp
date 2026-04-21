#pragma GCC optimize("O3,inline")
#include <iostream>
using namespace std;
#define int long long

int gcd(int a, int b) {
    if (b < a) return gcd(b, a);
    if (a == 0) return b;
    return gcd(b % a, a);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K, a, mv = 0, cg = -1; cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a;
        mv = max(mv, a);
        if (cg == -1) cg = a;
        else cg = gcd(cg, a);
    }
    if (K % cg || K > mv) cout << "IMPOSSIBLE\n";
    else cout << "POSSIBLE\n";
}
