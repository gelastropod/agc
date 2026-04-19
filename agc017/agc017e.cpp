#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> p;

int fin(int n) {
	if (p[n] == n) return n;
	return p[n] = fin(p[n]);
}

void join(int a, int b) {
	p[fin(a)] = fin(b);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, H, a, b, c, d; cin >> N >> H;
	vector<int> f(2 * H, 0), vv(2 * H, 0), deg(2 * H, 0);
	for (int i = 0; i < 2 * H; i++) p.push_back(i);
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c >> d;
		int s = (c == 0 ? a - 1 : c + H - 1);
		int e = (d == 0 ? b + H - 1 : d - 1);
		f[s]++, f[e]--;
		deg[s]++, deg[e]++;
		join(s, e);
	}
	int die = 0;
	for (int i = 0; i < H; i++) if (f[i] < 0 || f[i + H] > 0) die = 1;
	for (int i = 0; i < 2 * H; i++) {
		if (fin(i) == i) vv[i] += abs(f[i]);
		else vv[fin(i)] += abs(f[i]), vv[i] = 1;
	}
	for (int i = 0; i < 2 * H; i++) if (deg[i] && vv[i] == 0) die = 1;
	cout << (die ? "NO\n" : "YES\n");
}
