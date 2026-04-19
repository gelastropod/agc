#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, a, b; cin >> N;
    vector<vector<int>> adjlist(N, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b; a--, b--;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> degs;
    vector<int> deg(N, 0), proc(N, 0);
    for (int i = 0; i < N; i++) {
        degs.push({ adjlist[i].size(), i });
        deg[i] = adjlist[i].size();
    }
    while (degs.size()) {
        auto i = degs.top(); degs.pop();
        if (i.first == 0) {
            cout << "First\n";
            return 0;
        }
        if (proc[i.second]) continue;
        proc[i.second] = 1;
        for (int j : adjlist[i.second]) {
            if (!proc[j]) {
                proc[j] = 1;
                for (int k : adjlist[j]) {
                    if (!proc[k]) {
                        deg[k]--;
                        degs.push({ deg[k], k });
                    }
                }
                break;
            }
        }
    }
    cout << "Second\n";
}
