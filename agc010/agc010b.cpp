#include <iostream>
#include <vector>
using namespace std;
#define int long long

signed main() {
	int N, x, sum = 0;
	vector<int> A;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		A.push_back(x);
		sum += x;
	}
	vector<int> diff;
	diff.push_back(A[0] - A.back());
	for (int i = 1; i < N; i++)
		diff.push_back(A[i] - A[i - 1]);
	int k = 2 * sum / N / (N + 1);
	if (k * N * (N + 1) != 2 * sum) {
		cout << "NO\n";
		return 0;
	}
	for (int i = 0; i < N; i++) {
		if ((k - diff[i]) % N || diff[i] > k) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}
