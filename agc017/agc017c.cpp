#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int N, M, a, b, ans = 0; cin >> N >> M;
    vector<int> freq(N, 0), nump(N, 0), A;
    for (int i = 0; i < N; i++) {
        cin >> a; a--;
        A.push_back(a);
        freq[a]++;
        if (a + 1 - freq[a] >= 0) nump[a + 1 - freq[a]]++;
    }
    for (int i = 0; i < N; i++) if (nump[i] == 0) ans++;
    for (int i = 0; i < M; i++) {
        cin >> a >> b; a--, b--;
        if (A[a] + 1 - freq[A[a]] >= 0) {
            nump[A[a] + 1 - freq[A[a]]]--;
            if (!nump[A[a] + 1 - freq[A[a]]]) ans++;
        }
        freq[A[a]]--;
        A[a] = b;
        freq[b]++;
        if (b + 1 - freq[b] >= 0) {
            if (!nump[b + 1 - freq[b]]) ans--;
            nump[b + 1 - freq[b]]++;
        }
        cout << ans << '\n';
    }
}
