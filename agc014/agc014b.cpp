#include <iostream>
#include <vector>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M, a, b, res = 0; cin >> N >> M;
	vector freq(N, 0);
	for (int i = 0; i < M; i++) {
		cin >> a >> b; a--, b--;
		freq[a]++, freq[b]++;
	}
	for (int i = 0; i < N; i++) res += freq[i] % 2;
	if (res <= 1) cout << "YES\n";
	else cout << "NO\n";
}
