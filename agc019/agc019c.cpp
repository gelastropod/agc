#pragma GCC optimize("O3,inline")
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node {
	int s, e, m, v;
	node *l, *r;

	node(int _s, int _e) : s(_s), e(_e), m((_s + _e) / 2), v(0) {
		if (s != e)
			l = new node(s, m),
			r = new node(m + 1, e);
	}

	void upd(int n, int x) {
		if (s == e) {
			v = x;
			return;
		}
		if (n <= m) l->upd(n, x);
		else r->upd(n, x);
		v = max(l->v, r->v);
	}

	int qry(int a, int b) {
		if (b < s || a > e) return 0;
		if (a <= s && b >= e) return v;
		return max(l->qry(a, b), r->qry(a, b));
	}
} *root;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x1, y1, x2, y2, N, x, y, flip = 0; cin >> x1 >> y1 >> x2 >> y2 >> N;
	if (x1 > x2) {
		swap(x1, x2);
		swap(y1, y2);
	}
	if (y1 > y2) {
		flip = 1;
		y1 = 100000000 - 1 - y1;
		y2 = 100000000 - 1 - y2;
	}
	vector<pair<int, int>> pts;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		if (flip) y = 100000000 - 1 - y;
		if (x1 <= x && x <= x2 && y1 <= y && y <= y2) pts.push_back({x, y});
	}
	if (pts.empty()) {
		cout << 100 * (x2 - x1 + y2 - y1) << '\n';
		return 0;
	}
	sort(pts.begin(), pts.end());
	vector<int> v;
	for (auto& i : pts) v.push_back(i.second);
	vector<int> uv = v;
	sort(uv.begin(), uv.end());
	uv.erase(unique(uv.begin(), uv.end()), uv.end());
	for (int i = 0; i < v.size(); i++) v[i] = lower_bound(uv.begin(), uv.end(), v[i]) - uv.begin();
	root = new node(0, v.size() - 1);
	for (int i = 0; i < v.size(); i++) root->upd(v[i], root->qry(0, v[i] - 1) + 1);
	int e = root->qry(0, v.size() - 1);
	long double ans = 100 * (x2 - x1 + y2 - y1) + e * (5 * M_PI - 20);
	if (e == min(x2 - x1, y2 - y1) + 1) ans += 5 * M_PI;
	cout << setprecision(15) << ans << '\n';
}
