#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

long long ans = 0;
int don = 0;
string s;
vector<vector<int>> adjlist;
vector<int> d, md, mdte, exist;

void dfs1(int n, int p) {
	for (int i : adjlist[n]) {
		if (i == p) continue;
		d[i] = d[n] + 1;
		dfs1(i, n);
		md[n] = max(md[n], md[i]);
		exist[n] += exist[i];
	}
	md[n]++;
}

void dfs2(int n, int p) {
	priority_queue<pair<int, int>> pq;
	for (int i : adjlist[n]) {
		if (i == p) continue;
		pq.push({ md[i], i });
	}
	for (int i : adjlist[n]) {
		if (i == p || i == pq.top().second) continue;
		mdte[i] = max(mdte[n] + 1, pq.top().first + 2);
		dfs2(i, n);
	}
	if (n != 0 && adjlist[n].size() == 1) return;
	auto t = pq.top();
	pq.pop();
	mdte[t.second] = mdte[n] + 1;
	if (pq.size()) mdte[t.second] = max(mdte[t.second], pq.top().first + 2);
	dfs2(t.second, n);
}

int dfs3(int n, int p) {
	int minv = INT_MAX, mv = -1, crntd = 0;
	if (mdte[n] < md[n] && s[n] == '1' && !don) crntd = don = 1;
	for (int i : adjlist[n]) {
		if (i == p) continue;
		mv = max(mv, dfs3(i, n));
		if (mdte[i] > md[i] && exist[i]) minv = min(minv, md[i] + 1);
	}
	if (mdte[n] < md[n]) {
		if (s[n] == '1') {
			if (crntd) {
				ans += md[n];
				return mdte[n] + 1;
			}
			ans += mdte[n];
			return -1;
		}
		else {
			if (mv == -1 && don) {
				ans += mdte[n] - min(mdte[n], minv);
				return -1;
			}
			if (mv == -1) mv = md[n];
			ans += mv - min(mv, minv);
			return max(mdte[n], min(mv, minv)) + 1;
		}
	}
	else if (mdte[n] == md[n]) {
		if (s[n] == '1') {
			ans += md[n];
		}
		else {
			ans += md[n] - min(md[n], minv);
		}
	}
	else {
		if (!exist[n]) return -1;
		ans += min(md[n] + 2, mdte[n]) - min(minv, md[n]);
		if (s[n] == '1') ans += min(minv, md[n]);
	}
	return -1;
}

signed main() {
	int N, a, b; cin >> N;
	adjlist.resize(N, vector<int>());
	d.resize(N, 0);
	md.resize(N, -1);
	mdte.resize(N, 0);
	exist.resize(N, 0);
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b; a--, b--;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	cin >> s;
	for (int i = 0; i < N; i++) exist[i] = s[i] - '0';
	dfs1(0, -1);
	dfs2(0, -1);
	dfs3(0, -1);
	cout << ans + 1 << '\n';
}
