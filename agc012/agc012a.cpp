#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, a, ans = 0; cin >> N;
	vector<int> A;
	for (int i = 0; i < 3 * N; i++) {
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < N; i++) ans += A[3 * N - i * 2 - 2];
	cout << ans << '\n';
}
