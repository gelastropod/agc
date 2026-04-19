#pragma GCC optimize("O3,inline")
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
#define int long long

#define IN(a, n) (a.lower_bound(n) != a.upper_bound(n))

int numC;
vector<int> p;

int fin(int n) {
	if (p[n] == n) return n;
	return p[n] = fin(p[n]);
}

void join(int a, int b) {
	a = fin(a), b = fin(b);
	if (a == b) return;
	p[a] = b;
	numC--;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, a, b; cin >> N;
	numC = N - 1;
	for (int i = 0; i < N; i++) p.push_back(i);
	vector<set<int>> al0(N, set<int>()), al1(N, set<int>());
	set<pair<int, int>> s;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b; a--, b--;
		al0[a].insert(b);
		al0[b].insert(a);
		s.insert({min(a, b), max(a, b)});
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b; a--, b--;
		al1[a].insert(b);
		al1[b].insert(a);
		pair<int, int> crnt = {min(a, b), max(a, b)};
		if (IN(s, crnt)) q.push(crnt);
		else s.insert(crnt);
	}
	while (q.size()) {
		auto i = q.front(); q.pop();
		i.first = fin(i.first), i.second = fin(i.second);
		if (i.first == i.second) continue;
		al0[i.first].erase(i.second);
		al0[i.second].erase(i.first);
		al1[i.first].erase(i.second);
		al1[i.second].erase(i.first);
		if ((al0[i.first].size() + al1[i.first].size()) > (al0[i.second].size() + al1[i.second].size())) swap(i.first, i.second);
		for (int j : al0[i.first]) {
			al0[j].erase(i.first);
			al0[j].insert(i.second);
			al0[i.second].insert(j);
			pair<int, int> crnt = {min(i.second, j), max(i.second, j)};
			if (IN(s, crnt)) q.push(crnt);
			else s.insert(crnt);
		}
		for (int j : al1[i.first]) {
			al1[j].erase(i.first);
			al1[j].insert(i.second);
			al1[i.second].insert(j);
			pair<int, int> crnt = {min(i.second, j), max(i.second, j)};
			if (IN(s, crnt)) q.push(crnt);
			else s.insert(crnt);
		}
		join(i.first, i.second);
	}
	//cout << numC;
	cout << (numC ? "NO\n" : "YES\n");
}
