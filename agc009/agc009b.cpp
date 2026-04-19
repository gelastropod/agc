#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> adjlist;

int dfs(int n) {
	vector<int> vals;
	for (int i : adjlist[n]) vals.push_back(dfs(i));
	sort(vals.begin(), vals.end());
	int coun = adjlist[n].size(), maxv = 0;
	for (int i : adjlist[n]) maxv = max(maxv, vals[adjlist[n].size() - coun] + coun--);
	return maxv;
}

signed main() {
	int N, x; cin >> N;
	adjlist.resize(N, vector<int>());
	for (int i = 1; i < N; i++) {
		cin >> x; x--;
		adjlist[x].push_back(i);
	}
	cout << dfs(0) << '\n';
}
