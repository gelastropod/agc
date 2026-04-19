#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, a, prev = -1, upping = -1, ans = 1; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (prev == -1 || prev == a) {
			prev = a;
			continue;
		}
		if ((upping == -1 || upping == 1) && prev < a) upping = 1, prev = a;
		else if ((upping == -1 || upping == 0) && prev > a) upping = 0, prev = a;
		else upping = -1, prev = a, ans++;
	}
	cout << ans << '\n';
}
