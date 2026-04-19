#include <bits/stdc++.h>
using namespace std;
#define int long long

#define MOD 1000000007

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M, K, a, b, c; cin >> N >> M >> K;
	vector<vector<int>> reqs(M, vector<int>(N - 1, -1));
	for (int i = 0; i < K; i++) {
		cin >> a >> b >> c; a--, b--;
		reqs[a][b] = c;
	}
	vector<vector<int>> dp(N, vector<int>((1LL << (N - 1)), 0));
	dp[0][0] = 1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N - 1; j++) {
			for (int mask = 0; mask < (1LL << (N - 1)); mask++) {
				if (!(mask & (1LL << j))) {
					dp[j + 1][mask] += dp[j][mask];
					dp[j + 1][mask] %= MOD;
				}
				int rmask = mask & ((1LL << j) - 1);
				int _mask = (mask >> j);
				int __mask = _mask - (_mask & (-_mask));
				int ___mask = (__mask << j) + rmask;
				if (!(___mask & (1LL << j))) ___mask += (1LL << j);
				dp[j + 1][___mask] += dp[j][mask];
				dp[j + 1][___mask] %= MOD;
			}
		}
		for (int mask = 0; mask < (1LL << (N - 1)); mask++) {
			for (int j = 0; j < N - 1; j++) if ((bool)(mask & (1LL << j)) != reqs[i][j] && reqs[i][j] != -1) dp[N - 1][mask] = 0;
			dp[0][mask] = dp[N - 1][mask];
		}
		for (int j = 1; j < N; j++) for (int mask = 0; mask < (1LL << (N - 1)); mask++) dp[j][mask] = 0;
	}
	int res = 0;
	for (int mask = 0; mask < (1LL << (N - 1)); mask++) {
		res += dp[0][mask];
		res %= MOD;
	}
	cout << res << '\n';
}
