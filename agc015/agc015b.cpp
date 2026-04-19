#pragma GCC optimize("O3,inline")
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int ans = s.size() * (s.size() - 1);
	for (int i = 0; i < s.size(); i++) ans += (s[i] == 'U' ? i : s.size() - 1 - i);
	cout << ans << '\n';
}
