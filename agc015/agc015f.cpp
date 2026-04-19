#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define MOD 1000000007

int val(int a, int b) {
	if (a > b) return val(b, a);
	if (a == 0) return 0;
	return val(b % a, a) + 1;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> fibo;
	int A = 1, B = 1;
	for (int i = 0; i < 92; i++) {
		fibo.push_back(A);
		int C = A + B;
		A = B, B = C;
	}
	/*
	vector<vector<pair<int, int>>> things(65, {});
	vector<vector<int>> othings(65, {}), oithings(65, {});
	for (int i = 1; i <= 10000; i++) {
		for (int j = i; j <= 10000; j++) {
			int res = val(i, j);
			if (res >= 0) {
				if (i >= fibo[res + 1] && j >= fibo[res + 2]) continue;
				things[res].push_back({ i, j });
				othings[res].push_back(i);
				oithings[res].push_back(j);
			}
		}
	}
	for (int i = 0; i < 65; i++) {
		othings[i].erase(unique(othings[i].begin(), othings[i].end()), othings[i].end());
		sort(oithings[i].begin(), oithings[i].end());
		oithings[i].erase(unique(oithings[i].begin(), oithings[i].end()), oithings[i].end());
		cout << i << ":\n";
		//for (auto& j : things[i]) cout << j.first << ' ' << j.second << '\n';
		for (int j : othings[i]) {
			cout << j << ": ";
			for (int k = j; k <= 10000; k++) {
				int res = val(j, k);
				if (res == i) {
					if (j > fibo[res + 1] || k >= fibo[res + 2]) continue;
					cout << k - j << ' ';
				}
			}
			cout << '\n';
		}
		//for (int j = 1; j <= 2000; j++) {
		//	if (lower_bound(oithings[i].begin(), oithings[i].end(), j) == upper_bound(oithings[i].begin(), oithings[i].end(), j)) cout << j << ' ';
		//}
		//for (int j : oithings[i]) cout << j << ' ';
		//cout << '\n';
	}*/
	vector<vector<pair<int, int>>> maybe(87, vector<pair<int, int>>());
	vector<vector<int>> vals(87, vector<int>());
	vals[1] = { 1, 2 };
	for (int i = 2; i <= 86; i++) {
		int crnt = fibo[i];
		vals[i].push_back(crnt);
		for (int j = i - 2; j >= -1; j -= 4) {
			crnt += (j == -1 ? 1 : fibo[j]);
			vals[i].push_back(crnt);
		}
		for (int j = (i + 1) % 4 - 1; j < i; j += 4) {
			crnt += (j == -1 ? 1 : fibo[j]);
			vals[i].push_back(crnt);
		}
	}
	for (int i = 2; i <= 86; i++) {
		maybe[i].push_back({ vals[i][0], vals[i - 1][0] });
		maybe[i].push_back({ vals[i].back(), vals[i - 1][0] });
		for (int j = 1; j < vals[i - 1].size() - j; j++) {
			maybe[i].push_back({ vals[i][j], vals[i - 1][j] });
			maybe[i].push_back({ vals[i][j], vals[i - 1][vals[i - 1].size() - j] });
		}
		for (int j = 1; j < vals[i - 1].size() - j - 1; j++) {
			maybe[i].push_back({ vals[i][vals[i].size() - j - 1], vals[i - 1][j] });
			maybe[i].push_back({ vals[i][vals[i].size() - j - 1], vals[i - 1][vals[i - 1].size() - j - 1] });
		}
		if (i % 2) maybe[i].push_back({ vals[i][vals[i].size() / 2], vals[i - 1][vals[i - 1].size() / 2] });
		sort(maybe[i].begin(), maybe[i].end());
	}
	int Q; cin >> Q;
	while (Q--) {
		cin >> A >> B;
		if (A > B) swap(A, B);
		if (A == 1) {
			cout << "1 " << B % MOD << '\n';
			continue;
		}
		if (A == 2 && B == 2) {
			cout << "1 4\n";
			continue;
		}
		int idx1 = (int)(upper_bound(fibo.begin(), fibo.end(), A) - fibo.begin()) - 1;
		int idx2 = (int)(upper_bound(fibo.begin(), fibo.end(), B) - fibo.begin()) - 1;
		int val = min(idx1, idx2 - 1);
		int ans = 0;
		for (auto& i : maybe[val]) {
			if (i.first <= A) {
				ans += (B - i.second) / i.first;
				ans %= MOD;
			}
			if (i.first <= B) {
				ans += (A - i.second) / i.first;
				ans %= MOD;
			}
		}
		cout << val << ' ' << ans << '\n';
	}
}
