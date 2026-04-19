#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
using namespace std;
#define int long long

vector<int> A;
vector<vector<int>> adjlist;

int dfs(int n, int p, int d) {
	int s = 1 - d;
	for (int i : adjlist[n]) {
		if (i == p) continue;
		if (A[i] < A[n] && dfs(i, n, 1 - d) == d) s = d;
	}
	return s;
}

signed main() {
	int N, a, b; cin >> N;
	adjlist.resize(N, vector<int>());
	for (int i = 0; i < N; i++) {
		cin >> a;
		A.push_back(a);
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b; a--, b--;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	for (int i = 0; i < N; i++) if (dfs(i, -1, 1)) cout << i + 1 << ' ';
}
