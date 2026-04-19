#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int ans = 100;
	vector<vector<int>> poss(26, vector<int>());
	for (int i = 0; i < s.size(); i++) poss[s[i] - 'a'].push_back(i);
	for (int i = 0; i < 26; i++) {
		int maxl = 0;
		for (int j = 0; j < (int)poss[i].size() - 1; j++) maxl = max(maxl, poss[i][j + 1] - poss[i][j] - 1);
		if (!poss[i].empty()) {
			maxl = max(maxl, max(poss[i][0], (int)s.size() - poss[i].back() - 1));
			ans = min(ans, maxl);
		}
	}
	cout << ans << '\n';
}
