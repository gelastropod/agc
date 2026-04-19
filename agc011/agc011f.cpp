#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node {
	int s, e, m;
	pair<int, int> v;
	node* l = nullptr, * r = nullptr;

	node(int _s, int _e) : s(_s), e(_e), m((_s + _e) / 2), v(0, 0) {}

	void prop() {
		if (s == e) return;
		if (l == nullptr)
			l = new node(s, m),
			r = new node(m + 1, e);
		if (v.first == -1) return;
		l->v = r->v = v;
		v.first = -1;
	}

	void upd(int a, int b, pair<int, int> x) {
		if (b < s || a > e) return;
		if (a <= s && b >= e) {
			v = x;
			return;
		}
		prop();
		l->upd(a, b, x);
		r->upd(a, b, x);
	}

	pair<int, int> qry(int a) {
		if (s == e) return v;
		if (v.first != -1) return v;
		if (a <= m) return l->qry(a);
		return r->qry(a);
	}
} *root;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K, a, b, all1 = 1; cin >> N >> K;
	root = new node(0, K - 1);
	vector<int> A, B, dp, dp1;
	A.push_back(0);
	dp.push_back(0);
	dp1.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		B.push_back(b);
		if (a * 2 > K && b == 1) {
			cout << "-1\n";
			return 0;
		}
		if (b == 2) all1 = 0;
		A.push_back(a * 2);
	}
	for (int i = 1; i <= N; i++) A[i] += A[i - 1];
	for (int i = 1; i <= N; i++) {
		auto res = root->qry(A[i] % K);
		if (res.first == 0) dp.push_back(A[i]);
		else dp.push_back(K * (A[i] / K - res.second) + dp[res.first]);
		if (B[i - 1] == 2) continue;
		if (A[i] % K < (A[i - 1] + 1) % K) {
			root->upd(0, A[i] % K, { i, A[i] / K });
			root->upd((A[i - 1] + 1) % K, K - 1, { i, A[i] / K - 1 });
			continue;
		}
		root->upd((A[i - 1] + 1) % K, A[i] % K, { i, A[i] / K });
	}
	if (all1) {
		int ans = 1e17, t = 0;
		for (int i = N - 1; i >= 0; i--) {
			bool die = 0;
			if (A.back() - A[i + 1] - t > K) break;
			ans = min(ans, dp[i + 1] + A.back() - A[i + 1]);
		}
		cout << ans << '\n';
		return 0;
	}
	root->upd(0, K - 1, { 0, 0 });
	for (int i = 1; i <= N; i++) {
		auto res = root->qry((A.back() - A[N - i]) % K);
		if (res.first == 0) dp1.push_back(A.back() - A[N - i]);
		else dp1.push_back(K * ((A.back() - A[N - i]) / K - res.second) + dp1[res.first]);
		if (B[N - i] == 2) continue;
		if ((A.back() - A[N - i]) % K < (A.back() - A[N - i + 1] + 1) % K) {
			root->upd(0, (A.back() - A[N - i]) % K, { i, (A.back() - A[N - i]) / K });
			root->upd((A.back() - A[N - i + 1] + 1) % K, K - 1, { i, (A.back() - A[N - i]) / K - 1 });
			continue;
		}
		root->upd((A.back() - A[N - i + 1] + 1) % K, (A.back() - A[N - i]) % K, {i, (A.back() - A[N - i]) / K});
	}
	int ans = 1e17;
	for (int i = 0; i <= N; i++) ans = min(ans, dp[i] + dp1[N - i]);
	cout << ans << '\n';
}
