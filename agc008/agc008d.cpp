#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int N, x; cin >> N;
	vector<int> a;
	queue<int> b;
	vector<pair<int, int>> X;
	for (int i = 0; i < N; i++) {
		cin >> x; x--;
		X.push_back({ x, i });
	}
	sort(X.begin(), X.end());
	for (int i = 0; i < N; i++) for (int j = 0; j < X[i].second; j++) b.push(X[i].second);
	for (int i = 0; i < N; i++) for (int j = X[i].second + 1; j < N; j++) b.push(X[i].second);
	vector<int> freq(N, 0);
	for (int i = 0; i < N; i++) {
		while ((int)a.size() < X[i].first) {
			a.push_back(b.front());
			freq[b.front()]++;
			b.pop();
		}
		if (freq[X[i].second] != X[i].second) {
			cout << "No\n";
			return 0;
		}
		freq[X[i].second]++;
		a.push_back(X[i].second);
	}
	while ((int)a.size() < N * N) {
	  a.push_back(b.front());
	  b.pop();
	}
	cout << "Yes\n";
	for (int i = 0; i < N * N; i++) cout << a[i] + 1 << ' ';
	cout << '\n';
}
