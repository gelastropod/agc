#include <bits/stdc++.h>
using namespace std;
#define int long long

#define MOD 1000000007

int n;
vector<pair<int, int>> bounds;
vector<vector<vector<int>>> mem;

int dp(int a, int b, int c) {
    if (c < 0 || b < 0 || b + c > bounds[a].second - bounds[a].first) return 0;
    if (a == 0) return 1;
    if (mem[a][b][c] != -1) return mem[a][b][c];
    if (b == 0) {
        int res = (bounds[a].first == bounds[a - 1].first ? dp(a - 1, b, c - (bounds[a].second != bounds[a - 1].second)) : 0);
        for (int i = (bounds[a].first == bounds[a - 1].first); i < n; i++) res += dp(a - 1, i, c - 1 - (bounds[a].second != bounds[a - 1].second));
        return mem[a][b][c] = res % MOD;
    }
    if (c == 0) {
        int res = (bounds[a].second == bounds[a - 1].second ? dp(a - 1, b - (bounds[a].first != bounds[a - 1].first), c) : 0);
        for (int i = (bounds[a].second == bounds[a - 1].second); i < n; i++) res += dp(a - 1, b - 1 - (bounds[a].first != bounds[a - 1].first), i);
        return mem[a][b][c] = res % MOD;
    }
    int res = dp(a - 1, b - (bounds[a].first != bounds[a - 1].first), c - (bounds[a].second != bounds[a - 1].second));
    for (int i = b + (bounds[a].first == bounds[a - 1].first); i < n; i++) res += dp(a - 1, i, c - 1 - (bounds[a].second != bounds[a - 1].second));
    for (int i = c + (bounds[a].second == bounds[a - 1].second); i < n; i++) res += dp(a - 1, b - 1 - (bounds[a].first != bounds[a - 1].first), i);
    return mem[a][b][c] = res % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, a; cin >> N;
    vector<int> A, u;
    for (int i = 0; i < 2 * N - 1; i++) {
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());
    u = A;
    u.erase(unique(u.begin(), u.end()), u.end());
    for (int i = 0; i < N; i++) bounds.push_back({ lower_bound(u.begin(), u.end(), A[N - 1 - i]) - u.begin(), lower_bound(u.begin(), u.end(), A[N - 1 + i]) - u.begin() });
    mem.resize(N, vector<vector<int>>(u.size(), vector<int>(u.size(), -1)));
    n = u.size();
    int ans = 0;
    //for (int i = 0; i < N; i++) {
    //    for (int j = 0; j < u.size(); j++) {
    //        for (int k = 0; k < u.size(); k++) cout << dp(i, j, k) << ' ';
    //        cout << '\n';
    //    }
    //    cout << '\n';
    //}
    for (int i = 0; i < u.size(); i++) for (int j = 0; j < u.size(); j++) ans += dp(N - 1, i, j);
    cout << ans % MOD << '\n';
}
