#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int a, b, c, d, e, f, g; cin >> a >> b >> c >> d >> e >> f >> g;
	if ((((a & 1) + (d & 1) + (e & 1)) == 2) && a && d && e) cout << 1 + (a / 2) * 2 + (d / 2) * 2 + (e / 2) * 2 + b << '\n';
	else if (((a & 1) + (d & 1) + (e & 1)) == 3) cout << 3 + (a / 2) * 2 + (d / 2) * 2 + (e / 2) * 2 + b << '\n';
	else cout << (a / 2) * 2 + (d / 2) * 2 + (e / 2) * 2 + b << '\n';
}
