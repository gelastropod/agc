#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, a, cnt = 0; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		cnt += (a % 2);
	}
	cout << ((cnt % 2) ? "NO" : "YES") << '\n';
}
