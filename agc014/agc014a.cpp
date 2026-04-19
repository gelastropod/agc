#pragma GCC optimize("O3,inline")
#include <iostream>
#include <vector>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, a, crntv, crntv1, ans = 1; cin >> N;
	crntv = N - 1;
	vector<int> pos(N, -1);
	for (int i = 0; i < N; i++) {
		cin >> a; a--;
		pos[a] = i;
	}
	while (crntv && pos[crntv] > pos[crntv - 1]) crntv--;
	if (crntv == 0) {
		cout << "0\n";
		return 0;
	}
	crntv1 = crntv - 1;
	while (crntv1) {
		//cout << crntv << ' ' << crntv1 << '\n';
		vector<pair<int, int>> thing = {{pos[crntv], crntv}, {pos[crntv1], crntv1}, {pos[crntv1 - 1], crntv1 - 1}};
		sort(thing.begin(), thing.end());
		if ((thing[0].second == crntv && thing[1].second == crntv1 - 1) || (thing[0].second == crntv1 && thing[1].second == crntv) || (thing[0].second == crntv1 - 1 && thing[1].second == crntv1));
		else ans++, crntv = crntv1;
		crntv1--;
	}
	cout << ans << '\n';
}
