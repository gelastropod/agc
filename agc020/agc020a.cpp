#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, A, B; cin >> N >> A >> B;
	cout << ((A - B) % 2 ? "Borys" : "Alice") << '\n';
}
