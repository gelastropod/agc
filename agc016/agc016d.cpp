#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

int numC = 0;
vector<int> p;

int fin(int n) {
	if (p[n] == n) return n;
	return p[n] = fin(p[n]);
}

void join(int a, int b) {
	a = fin(a), b = fin(b);
	if (a == b) return;
	numC--;
	p[a] = b;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, a, xorr = 0, tdiff = 0, ans = 0, ans1 = 0; cin >> N;
	vector<int> v, A, B;
	for (int i = 0; i < N; i++) {
		cin >> a;
		A.push_back(a);
		v.push_back(a);
		xorr ^= a;
	}
	v.push_back(xorr);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	vector<int> freq(v.size(), 0), freq1(v.size(), 0);
	freq[lower_bound(v.begin(), v.end(), xorr) - v.begin()]++;
	for (int i : A) freq[lower_bound(v.begin(), v.end(), i) - v.begin()]++;
	for (int i = 0; i < N; i++) {
		cin >> a;
		B.push_back(a);
		if (lower_bound(v.begin(), v.end(), a) == upper_bound(v.begin(), v.end(), a)) {
			cout << "-1\n";
			return 0;
		}
		freq1[lower_bound(v.begin(), v.end(), a) - v.begin()]++;
	}
	for (int i = 0; i < v.size(); i++) tdiff += abs(freq[i] - freq1[i]);
	if (tdiff != 1) {
		cout << "-1\n";
		return 0;
	}
	for (int i = 0; i < v.size(); i++) p.push_back(i);
	vector<vector<int>> vals(v.size(), vector<int>());
	vector<int> uu;
	for (int i = 0; i < N; i++) {
		if (A[i] == B[i]) continue;
		uu.push_back(A[i]);
		uu.push_back(B[i]);
	}
	sort(uu.begin(), uu.end());
	uu.erase(unique(uu.begin(), uu.end()), uu.end());
	numC = uu.size();
	for (int i = 0; i < N; i++) {
		if (A[i] == B[i]) continue;
		if (B[i] == xorr) ans1 = -1;
		join(lower_bound(v.begin(), v.end(), A[i]) - v.begin(), lower_bound(v.begin(), v.end(), B[i]) - v.begin());
		ans++;
	}
	cout << ans + ans1 + numC << '\n';
}
