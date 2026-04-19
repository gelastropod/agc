#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int x, y; cin >> x >> y;
	if (abs(x) > abs(y)) cout << (x > 0) + abs(x) - abs(y) + (y > 0) << '\n';
	else if (abs(x) < abs(y)) cout << (x < 0) + abs(y) - abs(x) + (y < 0) << '\n';
	else cout << "1\n";
}
