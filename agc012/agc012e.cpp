#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, V, x; cin >> N >> V;
    vector<int> X;
    vector<vector<int>> reachr(22, vector<int>(N, -1)), reachl(22, vector<int>(N, -1));
    for (int i = 0; i < N; i++) {
        cin >> x;
        X.push_back(x);
    }
    int numS = log2(V) + 1;
    for (int i = 0; i <= numS; i++) {
        int prev = -2e9, crnti = -1;
        for (int j = 0; j < N; j++) {
            if (X[j] - prev > (V >> i)) crnti = j;
            reachl[i][j] = crnti, prev = X[j];
        }
        prev = 2e9, crnti = -1;
        for (int j = N - 1; j >= 0; j--) {
            if (prev - X[j] > (V >> i)) crnti = j;
            reachr[i][j] = crnti, prev = X[j];
        }
    }
    //for (int i = 0; i < numS; i++) {
    //    for (int j = 0; j < N; j++) cout << reachr[i][j] << ' ';
    //    cout << '\n';
    //    for (int j = 0; j < N; j++) cout << reachl[i][j] << ' ';
    //    cout << '\n';
    //}
    vector<int> dp1(1LL << numS, 0), dp2(1LL << numS, N - 1), rangr(N + 1, N);
    for (int i = 0; i < (1LL << numS); i++) {
        for (int j = 0; j < numS; j++) {
            if (i & (1LL << j)) continue;
            dp1[i + (1LL << j)] = (dp1[i] == N ? N : max(dp1[i + (1LL << j)], reachr[j + 1][dp1[i]] + 1));
            dp2[i + (1LL << j)] = (dp2[i] == -1 ? -1 : min(dp2[i + (1LL << j)], reachl[j + 1][dp2[i]] - 1));
        }
    }
    //for (int i = 0; i < (1LL << numS); i++) cout << dp1[i] << ' ';
    //cout << '\n';
    //for (int i = 0; i < (1LL << numS); i++) cout << dp2[i] << ' ';
    //cout << '\n';
    for (int i = 0; i < (1LL << numS); i++)
        rangr[dp1[i]] = min(rangr[dp1[i]], dp2[(1LL << numS) - 1 - i]);
    for (int i = N - 1; i >= 0; i--) rangr[i] = min(rangr[i], rangr[i + 1]);
    //for (int i = 0; i <= N; i++) cout << rangr[i] << ' ';
    //cout << '\n';
    for (int i = 0; i < N; i++)
        cout << (rangr[reachl[0][i]] <= reachr[0][i] ? "Possible" : "Impossible") << '\n';
}
