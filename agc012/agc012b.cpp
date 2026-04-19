#include <vector>
#include <iostream>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, Q, a, b, c; cin >> N >> M;
    vector<vector<int>> adjlist(N, vector<int>()), quers(N, vector<int>(11, -1));
    vector<int> C, finvs(N, -1);
    for (int i = 0; i < M; i++) {
        cin >> a >> b; a--, b--;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> a >> b >> c; a--;
        quers[a][b] = i;
        C.push_back(c);
    }
    for (int i = 0; i < N; i++) for (int j = 9; j >= 0; j--) quers[i][j] = max(quers[i][j], quers[i][j + 1]);
    for (int i = 0; i <= 10; i++) {
        vector<int> vals(N, -1), nvals(N, -1);
        for (int j = 0; j < N; j++) vals[j] = nvals[j] = quers[j][i];
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < N; k++) for (int l : adjlist[k]) nvals[k] = max(nvals[k], vals[l]);
            vals = nvals;
        }
        for (int j = 0; j < N; j++) finvs[j] = max(finvs[j], vals[j]);
    }
    for (int i = 0; i < N; i++) cout << (finvs[i] == -1 ? 0 : C[finvs[i]]) << '\n';
}
