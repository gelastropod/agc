#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
#include <climits>
using namespace std;
#define int long long

signed main() {
    int N, M, a, b, numcc = 0, numbc = 0, nums = 0; cin >> N >> M;
    vector<vector<int>> adjlist(N, vector<int>());
    for (int i = 0; i < M; i++) {
        cin >> a >> b; a--, b--;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    vector<int> visited(N, 0);
    queue<int> bfs;
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        int isb = 1, iss = 1;
        bfs.push(i);
        visited[i] = 1;
        while (bfs.size()) {
            int j = bfs.front();
            bfs.pop();
            for (int k : adjlist[j]) {
                if (visited[k] && visited[k] != 3 - visited[j]) isb = 0;
                if (visited[k]) continue;
                iss = 0;
                bfs.push(k);
                visited[k] = 3 - visited[j];
            }
        }
        numbc += isb && !iss;
        numcc += !iss;
        nums += iss;
    }
    cout << numcc * numcc + numbc * numbc + N * N - (N - nums) * (N - nums) << '\n';
}
