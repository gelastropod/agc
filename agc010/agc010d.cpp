#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, a, sum = 0, numodd = 0, minv = INT_MAX, count = 0; cin >> N;
	vector<int> A;
	for (int i = 0; i < N; i++) {
		cin >> a;
		A.push_back(a);
		sum += a - 1;
		numodd += a & 1;
		minv = min(minv, a);
	}
	if (N == 1) {
		cout << (sum & 1 ? "First" : "Second") << '\n';
		return 0;
	}
	while ((sum & 1) == 0 && numodd == 1 && minv > 1) {
		for (int i = 0; i < N; i++) A[i] /= 2;
		int crntgcd = A[0];
		for (int i = 1; i < N; i++) crntgcd = gcd(crntgcd, A[i]);
		sum = 0, numodd = 0, minv = INT_MAX;
		for (int i = 0; i < N; i++) {
			A[i] /= crntgcd;
			sum += A[i] - 1;
			numodd += A[i] & 1;
			minv = min(minv, A[i]);
		}
		count++;
	}
	cout << ((count + sum) & 1 ? "First" : "Second") << '\n';
}
