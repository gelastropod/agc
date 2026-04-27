#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string A, B; cin >> A >> B;
    int ans = INT_MAX, N = A.size();
    vector<int> poss;
    for (int i = 0; i < N; i++) if (B[i] == '1') poss.push_back(i);
    if (poss.size()) {
        poss.push_back(poss.back() - N);
        poss.push_back(poss[0] + N);
    }
    sort(poss.begin(), poss.end());
    for (int i = 0; i < N; i++) {
        int err = 0, die = 0;
        vector<pair<int, int>> vals;
        for (int j = 0; j < N; j++) {
            if (A[j] == B[j]) continue;
            if (poss.empty()) {
                die = 1;
                break;
            }
            int pos1 = *lower_bound(poss.begin(), poss.end(), j);
            int pos2 = *(--upper_bound(poss.begin(), poss.end(), j));
            vals.push_back({pos1 - j, j - pos2});
            err++;
        }
        char a = A[0];
        A = A.substr(1, A.size() - 1);
        A += string(1, a);
        if (die) continue;
        sort(vals.begin(), vals.end());
        int crntr = 0;
        for (int j = vals.size() - 1; j >= 0; j--) {
            int crntl = vals[j].first;
            int v1 = abs(i - crntl), v2 = (i + crntr) % N;
            ans = min(ans, err + min(crntr * 2 + crntl + min(v1, N - v1), crntl * 2 + crntr + min(v2, N - v2)));
            crntr = max(crntr, vals[j].second);
        }
        int v1 = i, v2 = (i + crntr) % N;
        ans = min(ans, err + min(crntr * 2 + min(v1, N - v1), crntr + min(v2, N - v2)));
    }
    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}
