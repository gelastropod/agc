#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define MOD 1000000007

struct node {
	int s, e, m, v, lazy;
	node* l, * r;

	node(int _s, int _e) : s(_s), e(_e), m((_s + _e) / 2), v(0), lazy(1) {
		if (s != e)
			l = new node(s, m),
			r = new node(m + 1, e);
	}

	void prop() {
		if (s == e || lazy == 1) return;
		l->v *= lazy;
		l->v %= MOD;
		l->lazy *= lazy;
		l->lazy %= MOD;
		r->v *= lazy;
		r->v %= MOD;
		r->lazy *= lazy;
		r->lazy %= MOD;
		lazy = 1;
	}

	void upd(int n, int x) {
		if (s == e) {
			v = (v + x) % MOD;
			return;
		}
		prop();
		if (n <= m) l->upd(n, x);
		else r->upd(n, x);
		v = (l->v + r->v) % MOD;
	}

	void upd(int a, int b, int x) {
		if (b < s || a > e) return;
		if (a <= s && b >= e) {
			v = (v * x) % MOD;
			lazy = (lazy * x) % MOD;
			return;
		}
		prop();
		l->upd(a, b, x);
		r->upd(a, b, x);
		v = (l->v + r->v) % MOD;
	}

	int qry(int a, int b) {
		if (b < s || a > e) return 0;
		if (a <= s && b >= e) return v;
		prop();
		return (l->qry(a, b) + r->qry(a, b)) % MOD;
	}
} *root;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, a, b; cin >> N;
	vector<pair<int, int>> dat;
	vector<int> uv, A;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		dat.push_back({ a, b });
		uv.push_back(b);
	}
	sort(dat.begin(), dat.end());
	sort(uv.begin(), uv.end());
	uv.erase(unique(uv.begin(), uv.end()), uv.end());
	for (int i = 0; i < N; i++) A.push_back(lower_bound(uv.begin(), uv.end(), dat[i].second) - uv.begin());
	vector<pair<int, int>> rangs(N, { -1, N });
	for (int i = 0; i < N; i++) rangs[i] = { A[i], A[i] };
	for (int i = 1; i < N; i++) rangs[i].second = max(rangs[i].second, rangs[i - 1].second);
	for (int i = N - 2; i >= 0; i--) rangs[i].first = min(rangs[i].first, rangs[i + 1].first);
	sort(rangs.begin(), rangs.end());
	root = new node(0, N);
	root->upd(0, 1);
	for (int i = 0; i < N; i++) {
		root->upd(rangs[i].second + 1, N, 2);
		root->upd(rangs[i].second + 1, root->qry(rangs[i].first, rangs[i].second));
	}
	cout << root->qry(N, N) << '\n';
}
