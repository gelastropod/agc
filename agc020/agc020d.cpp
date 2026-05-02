#pragma GCC optimize("O3,inline")
#include <iostream>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int Q; cin >> Q;
    while (Q--) {
        int A, B, C1, D; cin >> A >> B >> C1 >> D; C1--, D--;
        if (A == B) {
            for (int i = C1; i <= D; i++) cout << (i % 2 ? 'B' : 'A');
            cout << '\n';
            continue;
        }
        int C = (A + B) / (min(A, B) + 1);
        if (A > B * C) {
            for (int i = C1; i <= D; i++) cout << ((i + 1) % (C + 1) ? 'A' : 'B');
            cout << '\n';
            continue;
        }
        if (B > A * C) {
            for (int i = C1; i <= D; i++) cout << ((A + B - i) % (C + 1) ? 'B' : 'A');
            cout << '\n';
            continue;
        }
        int K1 = (A * C - B) / (C * C - 1);
        int K2 = (B * C - A) / (C * C - 1);
        int A1 = A - K1 * C - K2, B1 = B - K2 * C - K1;
        for (int i = C1; i <= D; i++) {
            if (i < K1 * (C + 1)) cout << ((i + 1) % (C + 1) ? 'A' : 'B');
            else if (i < K1 * (C + 1) + A1 + B1) cout << (i < (K1 * (C + 1) + A1) ? 'A' : 'B');
            else cout << ((i - K1 * (C + 1) - A1 - B1) % (C + 1) ? 'B' : 'A');
        }
        cout << '\n';
    }
}
