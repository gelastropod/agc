#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int H, W, h, w; cin >> H >> W >> h >> w;
	if (H % h || W % w) {
		cout << "Yes\n";
		int num = 999999999 / (h * w);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (i % h == h - 1 && j % w == w - 1) cout << -num * (h * w - 1) - 1 << ' ';
				else cout << num << ' ';
			}
			cout << '\n';
		}
	}
	else cout << "No\n";
}
