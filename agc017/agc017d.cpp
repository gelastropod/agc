#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> adjlist;

int dfs(int n, int p) {
    int crnt = 0;
    for (int i : adjlist[n]) {
        if (i == p) continue;
        crnt ^= (dfs(i, n) + 1);
    }
    return crnt;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int N, a, b; cin >> N;
    adjlist.resize(N, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b; a--, b--;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    if (dfs(0, -1)) cout << "Alice\n";
    else cout << "Bob\n";
}
