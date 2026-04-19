#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
using namespace std;
#define int long long

string N9 = "";

string add(string a, string b) {
	int carry = 0;
	string res = "";
	if (a.size() < b.size()) swap(a, b);
	b.resize(a.size(), '0');
	for (int i = 0; i < a.size(); i++) {
		int crnt = carry + (int)a[i] + (int)b[i] - 2 * (int)'0';
		res += '0' + crnt % 10;
		carry = crnt >= 10;
	}
	if (carry) res += '1';
	return res;
}

int inc() {
	int idx = 0, d = 1;
	while (idx < N9.size() && N9[idx] == '9') N9[idx] = '0', idx++, d -= 9;
	if (idx == N9.size()) N9 += '1';
	else N9[idx]++;
	return d;
}

int cnt(string x) {
	int ans = 0;
	for (char i : x) ans += i - '0';
	return ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ans = 0, ccnt = 0;
    string N; cin >> N;
    reverse(N.begin(), N.end());
    N9 = add(N, N);
    N9 = add(N9, N9);
    N9 = add(N9, N9);
    N9 = add(N9, N);
    ccnt = cnt(N9);
    while (ccnt > ans || (ans - ccnt) % 9) {
    	ans++;
    	ccnt += inc();
    }
    cout << (ans + 8) / 9 << '\n';
}
