#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> A;
vector<vector<int>> adjlist;

int dfs(int n, int p) {
	if (adjlist[n].size() == 1) return A[n];
	int sum = 0, maxd = 0;
	for (int i : adjlist[n]) {
		if (i == p) continue;
		int res = dfs(i, n);
		if (res == -1) return -1;
		if (!res) continue;
		if (sum == 0) {
			sum = res;
			continue;
		}
		if (sum <= res) maxd = sum;
		else if (sum - 2 * maxd <= res) maxd = (sum + res) / 2;
		else maxd += res;
		sum += res;
	}
	if (sum >= A[n] && sum - A[n] <= maxd) return 2 * A[n] - sum;
	return -1;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, a, b; cin >> N;
	adjlist.resize(N, vector<int>());
	for (int i = 0; i < N; i++) {
		cin >> a;
		A.push_back(a);
	}
	if (N == 2) {
		cout << (A[0] == A[1] ? "YES" : "NO") << '\n';
		return 0;
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b; a--, b--;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		if (adjlist[i].size() > 1) {
			cout << (dfs(i, -1) == 0 ? "YES" : "NO") << '\n';
			return 0;
		}
	}
}
