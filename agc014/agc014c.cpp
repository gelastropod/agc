#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int H, W, K, ans = INT_MAX; cin >> H >> W >> K;
	string s, grid = "";
	queue<pair<int, int>> bfs;
	vector<int> visited(H * W, 0);
	for (int i = 0; i < H; i++) {
		cin >> s;
		grid += s;
		for (int j = 0; j < W; j++) {
			if (s[j] == 'S') {
				visited[i * W + j] = 1;
				bfs.push({ i * W + j, 0 });
			}
		}
	}
	s = grid;
	while (bfs.size()) {
		auto i = bfs.front(); bfs.pop();
		if (i.second > K) continue;
		int x = i.first % W, y = i.first / W;
		ans = min(ans, 1 + (min(min(W - x - 1, x), min(H - y - 1, y)) + K - 1) / K);
		if (i.first % W > 0 && !visited[i.first - 1] && s[i.first - 1] != '#') {
			visited[i.first - 1] = 1;
			bfs.push({ i.first - 1, i.second + 1 });
		}
		if (i.first % W < W - 1 && !visited[i.first + 1] && s[i.first + 1] != '#') {
			visited[i.first + 1] = 1;
			bfs.push({ i.first + 1, i.second + 1 });
		}
		if (i.first >= W && !visited[i.first - W] && s[i.first - W] != '#') {
			visited[i.first - W] = 1;
			bfs.push({ i.first - W, i.second + 1 });
		}
		if (i.first < (H - 1) * W && !visited[i.first + W] && s[i.first + W] != '#') {
			visited[i.first + W] = 1;
			bfs.push({ i.first + W, i.second + 1 });
		}
	}
	cout << ans << '\n';
}
