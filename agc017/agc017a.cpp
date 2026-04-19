#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> mem;

int choose(int a, int b) {
	if (b == 0 || b == a) return 1;
	if (mem[a][b] != -1) return mem[a][b];
	return mem[a][b] = choose(a - 1, b - 1) + choose(a - 1, b);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, P, a, cnt = 0, res = 0; cin >> N >> P;
	mem.resize(N + 1, vector<int>(N + 1, -1));
	for (int i = 0; i < N; i++) {
		cin >> a;
		cnt += (a % 2);
	}
	for (int i = P; i <= cnt; i += 2) res += choose(cnt, i);
	cout << res * (1LL << (N - cnt)) << '\n';
}
