#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, L, T, a, b; cin >> N >> L >> T;
	vector<int> A, B;
	vector<pair<int, int>> vals;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		vals.push_back({ a, b });
		if (b == 1) {
			A.push_back(a);
			A.push_back(a + L);
		}
		else {
			B.push_back(a);
			B.push_back(a + L);
		}
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	vector<int> fin(N, 0);
	for (int i = 0; i < N; i++) {
		if (vals[i].second == 1) fin[(i + (T * 2) / L * ((int)B.size() / 2) + (int)(lower_bound(B.begin(), B.end(), vals[i].first + (T * 2) % L) - lower_bound(B.begin(), B.end(), vals[i].first))) % N] = (vals[i].first + T) % L;
		else fin[((i - (T * 2) / L * ((int)A.size() / 2) - (int)(lower_bound(A.begin(), A.end(), vals[i].first + L) - upper_bound(A.begin(), A.end(), vals[i].first + L - (T * 2) % L))) % N + N) % N] = ((vals[i].first - T) % L + L) % L;
	}
	for (int i : fin) cout << i << '\n';
}
