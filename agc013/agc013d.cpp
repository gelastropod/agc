#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define MOD 1000000007

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M, ans = 0, fact = 1; cin >> N >> M;
	vector dp(M + 1, vector(N + 1, 0LL));
	for (int _ = N; _ >= N - 1; _--) {
		for (int i = 0; i <= _; i++) dp[0][i] = 1;
		for (int i = 1; i <= M; i++) {
			for (int j = 0; j <= _; j++) {
				dp[i][j] = 0;
				if (j != 0) dp[i][j] += dp[i - 1][j] + dp[i - 1][j - 1];
				if (j != _) dp[i][j] += dp[i - 1][j] + dp[i - 1][j + 1];
				dp[i][j] %= MOD;
			}
		}
		for (int i = 0; i <= _; i++) ans += dp[M][i] * fact, ans %= MOD;
		fact *= -1;
	}
	cout << (ans + MOD) % MOD << '\n';
}
