#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
#include <climits>
using namespace std;
#define int long long

signed main() {
	int N, C, K, a, ans = 0, prevt = INT_MIN, previ = 0; cin >> N >> C >> K;
	vector<int> T;
	for (int i = 0; i < N; i++) {
		cin >> a;
		T.push_back(a);
	}
	sort(T.begin(), T.end());
	for (int i = 0; i < N; i++) {
		if (T[i] - prevt > K || i - previ >= C) {
			ans++;
			prevt = T[i], previ = i;
		}
	}
	cout << ans << '\n';
}
