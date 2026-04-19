#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, a; cin >> N;
	int minv = N, maxv = 0, A = 0, B = 0;
	vector<int> _A;
	for (int i = 0; i < N; i++) {
		cin >> a;
		_A.push_back(a);
		minv = min(minv, a);
		maxv = max(maxv, a);
	}
	for (int i : _A) {
		if (i == minv) A++;
		else B++;
	}
	if (maxv - minv > 1) {
		cout << "No\n";
		return 0;
	}
	if (minv == maxv) {
		if (minv == N - 1 || minv <= N / 2) cout << "Yes\n";
		else cout << "No\n";
		return 0;
	}
	if (maxv - A <= (N - A) / 2 && maxv - A >= 1) cout << "Yes\n";
	else cout << "No\n";
}
