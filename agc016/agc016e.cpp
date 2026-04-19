#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int N, M, a, b, ans = 0; cin >> N >> M;
    vector<pair<int, int>> people;
    for (int i = 0; i < M; i++) {
        cin >> a >> b; a--, b--;
        people.push_back(pair<int, int>(a, b));
    }
    vector<vector<int>> ss(N, vector<int>(N, 0)), pairs(N, vector<int>(N, 1));
    vector<int> die(N, 0);
    for (int i = 0; i < N; i++) {
        ss[i][i] = 1;
        int _die = 0;
        for (int j = M - 1; j >= 0; j--) {
            a = people[j].first, b = people[j].second;
            if (ss[i][a] && ss[i][b]) {
                _die = 1;
                break;
            }
            if (ss[i][a] && !ss[i][b]) ss[i][b] = 1;
            if (ss[i][b] && !ss[i][a]) ss[i][a] = 1;
        }
        die[i] = _die;
    }
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) for (int k = j + 1; k < N; k++) if (die[j] || die[k] || (ss[j][i] && ss[k][i])) pairs[j][k] = 0;
    for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++) ans += pairs[i][j];
    cout << ans << '\n';
}
