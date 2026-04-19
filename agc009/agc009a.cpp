#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int N, a, b, crnt = 0; cin >> N;
	vector<pair<int, int>> vals;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		vals.push_back({ a, b });
	}
	for (int i = N - 1; i >= 0; i--) {
		a = vals[i].first, b = vals[i].second;
		int rem = ((b - (a % b)) % b);
		crnt = rem + ((max(0LL, crnt - rem) + b - 1) / b) * b;
	}
	cout << crnt << '\n';
}
