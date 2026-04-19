#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> adjlist;
vector<queue<int>> queues;

void dfs(int n, int p) {
	priority_queue<pair<int, int>> pq;
	stack<int> crnt;
	stack<pair<int, int>> h;
	for (int i : adjlist[n]) {
		if (i == p) continue;
		dfs(i, n);
		pq.push({ queues[i].front(), i });
		queues[i].pop();
	}
	while (pq.size()) {
		auto i = pq.top();
		pq.pop();
		crnt.push(i.first);
		if (pq.size() && pq.top().first == i.first) break;
		if (queues[i.second].size()) {
			pq.push({ queues[i.second].front(), i.second });
			queues[i.second].pop();
		}
	}
	if (pq.empty()) h.push({ 0, 1 });
	else {
		h.push({ crnt.top() + 1, 1 });
		crnt.pop();
	}
	while (crnt.size()) {
		if (h.top().first < crnt.top()) h.push({ crnt.top(), 0 });
		else h.push({ crnt.top() + 1, 1 });
		crnt.pop();
	}
	while (h.size() && !h.top().second) {
		queues[n].push(h.top().first);
		h.pop();
	}
	if (h.size()) queues[n].push(h.top().first);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, a, b; cin >> N;
	adjlist.resize(N, vector<int>());
	queues.resize(N, queue<int>());
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b; a--, b--;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	dfs(0, -1);
	cout << queues[0].front() << '\n';
}
