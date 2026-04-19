#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K; cin >> N >> K;
	string s; cin >> s;
	vector<int> S;
	for (char i : s) S.push_back(i == 'A');
	for (int i = 0; i < 3 * N; i++) S.push_back(i % 2);
	string fin;
	int crnt = 0;
	int idx = 0;
	for (int i = 0; i < min(3 * N, K); i++) {
		if (crnt ^ S[idx]) S[idx] = 1 - S[idx];
		else {
			idx++;
			crnt = 1 - crnt;
		}
	}
	if (K > 3 * N) {
		if (N % 2) cout << ((((K - 3 * N) % 2) ^ S[idx] ^ crnt) ? 'A' : 'B');
		for (int i = N % 2; i < N; i++) cout << ((N - i) % 2 ? 'A' : 'B');
		cout << '\n';
		return 0;
	}
	for (int i = 0; i < N; i++) {
		cout << ((crnt ^ S[idx + i]) ? 'A' : 'B');
	}
	cout << '\n';
}
