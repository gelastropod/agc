#include <bits/stdc++.h>
using namespace std;
#define int long long

int N;
vector<int> A, visited, ans;
vector<vector<int>> adjlist;
vector<queue<int>> vals;

void dfs(int n) {
	vals[n].push(n);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = adjlist[n].size() - 1; i >= 0; i--) {
		if (visited[adjlist[n][i]]) continue;
		visited[adjlist[n][i]] = 1;
		dfs(adjlist[n][i]);
		pq.push({ adjlist[n][i], adjlist[n][i] });
	}
	while (pq.size()) {
		vals[n].push(pq.top().first);
		int next = pq.top().second;
		pq.pop();
		vals[next].pop();
		if (vals[next].size()) pq.push({ vals[next].front(), next });
	}
}

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a; cin >> N;
	visited.resize(N + 1, 0);
	vals.resize(N + 1, {});
	for (int i = 0; i < N; i++) {
		cin >> a;
		A.push_back(a);
	}
	adjlist.resize(N + 1, {});
	sort(A.begin(), A.end(), greater<int>());
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (gcd(A[i], A[j]) != 1) {
				adjlist[i].push_back(j);
				adjlist[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < N; i++) adjlist[N].push_back(i);
	visited[N] = 1;
	dfs(N);
	vals[N].pop();
	while (vals[N].size()) {
		cout << A[vals[N].front()] << ' ';
		vals[N].pop();
	}
	cout << '\n';
}
