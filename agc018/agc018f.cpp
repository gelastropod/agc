#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> adjlistA, adjlistB;
vector<int> pA, pB, childA, childB, ans, visited;

void dfsA(int n, int p) {
	pA[n] = p;
    if (childA[n] % 2) dfsA(adjlistA[n][0], p);
    for (int i = childA[n] % 2; i < adjlistA[n].size(); i++) dfsA(adjlistA[n][i], n);
}

void dfsB(int n, int p) {
	pB[n] = p;
    if (childB[n] % 2) dfsB(adjlistB[n][0], p);
    for (int i = childB[n] % 2; i < adjlistB[n].size(); i++) dfsB(adjlistB[n][i], n);
}

vector<queue<pair<int, int>>> g;

void dfs(int n, int s) {
	while (g[n].size() && visited[g[n].front().second]) g[n].pop();
	if (g[n].empty()) return;
	auto i = g[n].front(); g[n].pop();
	visited[i.second] = 1;
	ans[i.second] = s;
	dfs(i.first, -s);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, a, rtA, rtB; cin >> N;
	adjlistA.resize(N, vector<int>());
	adjlistB.resize(N, vector<int>());
	pA.resize(N, -1);
	pB.resize(N, -1);
	childA.resize(N, 0);
	childB.resize(N, 0);
	ans.resize(N, 0);
	visited.resize(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> a; a--;
		if (a == -2) {
			rtA = i;
			continue;
		}
		adjlistA[a].push_back(i);
		childA[a]++;
	}
	for (int i = 0; i < N; i++) {
		cin >> a; a--;
		if (a == -2) {
			rtB = i;
			continue;
		}
		adjlistB[a].push_back(i);
		childB[a]++;
	}
	bool die = 0;
	for (int i = 0; i < N; i++) if (childA[i] % 2 != childB[i] % 2) die = 1;
	if (die) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	cout << "POSSIBLE\n";
	dfsA(rtA, -1);
	dfsB(rtB, -1);
	set<pair<pair<int, int>, int>> ss;
	g.resize(2 * N, queue<pair<int, int>>());
	for (int i = 0; i < N; i++) {
		if (childA[i] % 2) continue;
		if (pA[i] == -1 || pB[i] == -1) {
			ans[i] = 1;
            if (pA[i] == -1 && pB[i] != -1) rtA = N + pB[i];
            else if (pA[i] == -1) rtA = -1;
			continue;
		}
		g[pA[i]].push({N + pB[i], i});
        g[N + pB[i]].push({pA[i], i});
	}
    if (rtA != -1) dfs(rtA, -1);
	for (int i = 0; i < 2 * N; i++) dfs(i, 1);
	for (int i = 0; i < N; i++) cout << ans[i] << ' ';
	cout << '\n';
}
