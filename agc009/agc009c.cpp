#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
using namespace std;
#define int long long

#define MOD 1000000007

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, A, B, x; cin >> N >> A >> B;
	if (A > B) swap(A, B);
	vector<int> X, dp(N + 2, 0);
	vector<pair<int, int>> Y;
	dp[1] = 1, dp[2] = 2;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (X.size() >= 2 && x - X[X.size() - 2] < A) {
			cout << "0\n";
			return 0;
		}
		X.push_back(x);
	}
	Y.push_back({X[0], 0});
	for (int i = 1; i < N; i++) if (X[i] - X[i - 1] < A) Y.push_back({X[i], i});
	for (int i = 2; i <= N; i++) {
		int i1 = upper_bound(X.begin(), X.end(), X[i - 1] - B) - X.begin() + 1, i2 = (--upper_bound(Y.begin(), Y.end(), pair<int, int>(X[i - 2], N)))->second;
		if (i1 < i2) dp[i + 1] = dp[i];
		else dp[i + 1] = (MOD + dp[i] + dp[i1] - dp[i2]) % MOD;
	}
	cout << (MOD + dp[N + 1] - dp[(--upper_bound(Y.begin(), Y.end(), pair<int, int>(X[N - 1], N)))->second]) % MOD << '\n';
}
