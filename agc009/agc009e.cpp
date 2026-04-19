#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define MOD 1000000007

signed main() {
	int N, M, K, n, ans = 0; cin >> N >> M >> K;
	n = (N + M - 1) / (K - 1);
	vector<vector<int>> dp(n + 1, vector<int>(M + 2, 0));
	for (int i = 1; i < M + 2; i++) dp[0][i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= M; j++)
			dp[i][j + 1] = (MOD + dp[i][j] + dp[i - 1][j + 1] - dp[i - 1][max(0LL, j + 1 - K)]) % MOD;
	for (int i = 0; i < (M + K - 2) / (K - 1); i++) {
		ans += MOD + dp[n - i][M + 1 - i * (K - 1)] - dp[n - i][M - i * (K - 1)];
		ans %= MOD;
	}
	cout << ans << '\n';
}
