#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int A, B; cin >> A >> B;
	swap(A, B);
	for (int i = 59; i >= 0; i--) {
		if ((A & (1LL << i)) == (B & (1LL << i))) continue;
		int guy = A & ((1LL << i) - 1);
		int ub = (guy ? (1LL << ((int)log2(guy) + 1)) - 1 : 0);
		int lb = B & ((1LL << i) - 1);
		if (lb > ub) cout << ((1LL << i) - lb) * 2 + ub + 1 << '\n';
		else cout << (1LL << i) * 2 - lb << '\n';
		return 0;
	}
	cout << "1\n";
}
