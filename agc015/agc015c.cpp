#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M, Q, a, b, c, d; cin >> N >> M >> Q;
	vector<string> grid;
	vector<vector<int>> hedges(N + 1, vector<int>(M + 1, 0)), vedges(N + 1, vector<int>(M + 1, 0)), people(N + 1, vector<int>(M + 1, 0));
	string s;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		grid.push_back(s);
		for (int j = 1; j <= M; j++) people[i][j] = grid[i - 1][j - 1] - '0';
	}
	for (int i = 1; i <= N; i++) for (int j = 2; j <= M; j++) hedges[i][j] = people[i][j] * people[i][j - 1];
	for (int i = 2; i <= N; i++) for (int j = 1; j <= M; j++) vedges[i][j] = people[i][j] * people[i - 1][j];
	for (int i = 1; i <= N; i++) for (int j = 2; j <= M; j++) people[i][j] += people[i][j - 1], hedges[i][j] += hedges[i][j - 1], vedges[i][j] += vedges[i][j - 1];
	for (int i = 2; i <= N; i++) for (int j = 1; j <= M; j++) people[i][j] += people[i - 1][j], hedges[i][j] += hedges[i - 1][j], vedges[i][j] += vedges[i - 1][j];
	for (int i = 0; i < Q; i++) {
		cin >> a >> b >> c >> d;
		cout << people[c][d] - people[a - 1][d] - people[c][b - 1] + people[a - 1][b - 1]
			  - hedges[c][d] + hedges[a - 1][d] + hedges[c][b] - hedges[a - 1][b]
			  - vedges[c][d] + vedges[a][d] + vedges[c][b - 1] - vedges[a][b - 1] << '\n';
	}
}
