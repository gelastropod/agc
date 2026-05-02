#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int K, a, l = 2, h = 2; cin >> K;
	vector<int> A;
	for (int i = 0; i < K; i++) {
		cin >> a;
		A.push_back(a);
	}
	for (int i = K - 1; i >= 0; i--) {
		l = ((l + A[i] - 1) / A[i]) * A[i];
		h = (h / A[i]) * A[i] + A[i] - 1;
		if (l > h) {
			cout << "-1\n";
			return 0;
		}
	}
	cout << l << ' ' << h << '\n';
}
