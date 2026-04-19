#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
using namespace std;
#define int long long

#define MOD 1000000007
#define die(a) if (a) { cout << "0\n"; return 0; }
#define upd(a) ans *= a; ans %= MOD

int upow(int a, int b) {
	if (a == 1 || b == 0) return 1;
	if (b & 1) return (a * upow(a, b - 1)) % MOD;
	int res = upow(a, b / 2);
	return (res * res) % MOD;
}

int uinv(int a) {
	return upow(a, MOD - 2);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, x, ans = 1; cin >> N;
	vector<int> X;
	vector<vector<int>> freq(N, vector<int>());
	for (int i = 0; i < N; i++) {
		cin >> x; x--;
		X.push_back(x);
		freq[x].push_back(i);
	}
	for (int i = 0; i < N; i++) {
		die(freq[i].size() > 2);
	}
	vector<bool> done(N, 0);
	for (int i = 0; i < N; i++) {
		if (freq[i].size() < 2) continue;
		done[freq[i][0]] = done[freq[i][1]] = 1;
		if (freq[i][0] == i || freq[i][1] == i) continue;
		pair<int, int> crnt = {freq[i][0], freq[i][1]};
		while (freq[crnt.first].size() == 1 && freq[crnt.second].size() == 1) {
			crnt.first = freq[crnt.first][0];
			crnt.second = freq[crnt.second][0];
			done[crnt.first] = done[crnt.second] = 1;
		}
		int crnts = freq[crnt.first].size() + freq[crnt.second].size(), nex;
		die(crnts == 0 || crnts > 2);
		if (crnts == 2) continue;
		upd(2);
		if (freq[crnt.first].size()) nex = freq[crnt.first][0];
		else nex = freq[crnt.second][0];
		done[nex] = 1;
		while (freq[nex].size() == 1) {
			nex = freq[nex][0];
			done[nex] = 1;
		}
		die(freq[nex].size() == 0);
	}
	for (int i = 0; i < N; i++) {
		if (done[i]) continue;
		die(freq[i].size() != 1);
	}
	vector<int> sfreq(N + 1, 0);
	for (int i = 0; i < N; i++) {
		if (done[i]) continue;
		int ci = i, csize = 0;
		while (!done[ci]) {
			csize++;
			done[ci] = 1;
			ci = freq[ci][0];
		}
		sfreq[csize]++;
	}
	//cout << ans << ' ';
	for (int i = 1; i <= N; i++) {
		int crnt = upow(((i & 1) && i > 2) + 1, sfreq[i]), crnt1 = crnt, crntn = sfreq[i];
		for (int j = 2; j <= sfreq[i]; j += 2) {
			crnt *= crntn;
			crnt %= MOD;
			crnt *= crntn - 1;
			crnt %= MOD;
			crntn -= 2;
			crnt *= i;
			crnt %= MOD;
			crnt *= uinv(j);
			crnt %= MOD;
			if ((i & 1) && i > 2) crnt *= uinv(4);
			crnt %= MOD;
			//cout << crnt << ' ';
			crnt1 += crnt;
			crnt1 %= MOD;
		}
		//cout << crnt1 << ' ';
		upd(crnt1);
	}
	cout << ans << '\n';
}
