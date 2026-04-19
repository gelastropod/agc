#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int N, K, a, ans = 0, crnt = -1e15, crnt1 = 0, crnt2 = 0; cin >> N >> K;
	queue<int> vals;
	vals.push(0);
	for (int i = 0; i < N; i++) {
		cin >> a;
		ans += max(a, 0LL);
		vals.push(a);
		if (i < K - 1) {
			crnt1 -= max(a, 0LL);
			crnt2 -= max(a, 0LL) - a;
		}
		else {
			crnt1 -= max(a, 0LL);
			crnt2 -= max(a, 0LL) - a;
			int f = vals.front();
			vals.pop();
			crnt1 += max(f, 0LL);
			crnt2 += max(f, 0LL) - f;
			crnt = max(crnt, max(crnt1, crnt2));
		}
	}
	cout << ans + crnt << '\n';
}
