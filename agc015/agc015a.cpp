#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> fib;
	int A = 1, B = 1;
	for (int i = 0; i < 100; i++) {
		fib.push_back(A);
		int C = A + B;
		A = B, B = C;
	}
	int N; cin >> N >> A >> B;
	if (A > B) cout << "0\n";
	else if (N == 1) {
		cout << (A == B) << '\n';
	}
	else {
		cout << (N - 2) * (B - A) + 1 << '\n';
	}
}
