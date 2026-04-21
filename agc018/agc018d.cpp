#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<pair<int, int>>> adjlist;
vector<int> ss, pw;
int pls = 0, plm = 2e13;

void dfs1(int n, int p) {
    for (auto i : adjlist[n]) {
        if (i.first == p) continue;
        pw[i.first] = i.second;        
        dfs1(i.first, n);
        ss[n] += ss[i.first];
    }
}

int dfs2(int n, int p, int k) {
    for (auto i : adjlist[n]) if (i.first != p && ss[i.first] * 2 >= k) return dfs2(i.first, n, k);
    return n;
}

void dfs3(int n, int p, int pl) {
    if (pl != 0) plm = min(plm, pl);
    pls += pl;
    for (auto i : adjlist[n]) if (i.first != p) dfs3(i.first, n, pl + i.second);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, a, b, c; cin >> N;
    ss.resize(N, 1);
    pw.resize(N, -1);
    adjlist.resize(N, vector<pair<int, int>>());
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> c; a--, b--;
        adjlist[a].push_back({b, c});
        adjlist[b].push_back({a, c});
    }
    dfs1(0, -1);
    int cent = dfs2(0, -1, ss[0]);
    dfs3(cent, -1, 0);
    if (ss[0] == ss[cent] * 2) cout << pls * 2 - pw[cent] << '\n'; 
    else cout << pls * 2 - plm << '\n';
}
