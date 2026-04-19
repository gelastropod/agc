#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> p1, p2, visited;
vector<vector<int>> adjlist;

void dfs(int n, int s) {
	visited[n] = 1;
	for (int i : adjlist[n]) {
		if (visited[i]) continue;
		if (s) p1.push_back(i);
		else p2.push_back(i);
		dfs(i, s);
		return;
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M, a, b; cin >> N >> M;
	adjlist.resize(N, vector<int>());
	visited.resize(N, 0);
	for (int i = 0; i < M; i++) {
		cin >> a >> b; a--, b--;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	visited[0] = 1;
	dfs(0, 0);
	dfs(0, 1);
	reverse(p1.begin(), p1.end());
	cout << p1.size() + p2.size() + 1 << '\n';
	for (int i : p1) cout << i + 1 << ' ';
	cout << 1 << ' ';
	for (int i : p2) cout << i + 1 << ' ';
	cout << '\n';
}
