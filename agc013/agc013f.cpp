#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> tree;

void upd(int n, int x) {
    while (n < tree.size()) {
        tree[n] += x;
        n += n & (-n);
    }
}

int qry(int a) {
    int ans = 0;
    while (a) {
        ans += tree[a];
        a -= a & (-a);
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, Q, a, b; cin >> N;
    vector<pair<int, int>> X;
    vector<int> Y, uv;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        X.push_back(pair<int, int>(a, b));
        uv.push_back(a);
        uv.push_back(b);
    }
    for (int i = 0; i < N + 1; i++) {
        cin >> a;
        Y.push_back(a);
        uv.push_back(a);
    }
    sort(uv.begin(), uv.end());
    uv.erase(unique(uv.begin(), uv.end()), uv.end());
    for (int i = 0; i < N; i++) {
        X[i].first = lower_bound(uv.begin(), uv.end(), X[i].first) - uv.begin();
        X[i].second = lower_bound(uv.begin(), uv.end(), X[i].second) - uv.begin();
    }
    for (int i = 0; i < N + 1; i++) Y[i] = lower_bound(uv.begin(), uv.end(), Y[i]) - uv.begin();
    tree.resize(uv.size() + 10, 0);
    for (int i = 0; i < N + 1; i++) upd(Y[i] + 1, -1);
    for (int i = 0; i < N; i++) upd(X[i].first + 1, 1);
    vector<vector<int>> rangs2(uv.size(), vector<int>());
    vector<vector<pair<int, int>>> rangs1(uv.size(), vector<pair<int, int>>());
    vector<pair<int, int>> rangs;
    vector<int> used;
    for (int i = 0; i < N; i++) {
        if (X[i].first <= X[i].second) continue;
        rangs1[X[i].first - 1].push_back(pair<int, int>(X[i].second, rangs.size()));
        rangs.push_back(pair<int, int>(X[i].second, X[i].first - 1));
        used.push_back(0);
    }
    int ans1 = 0, die = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1;
    for (int i = uv.size() - 1; i >= 0 && !die; i--) {
        for (auto j : rangs1[i]) pq1.push(j);
        while (qry(i + 1) < -1) {
            if (pq1.empty()) {
                die = 1;
                break;
            }
            ans1++;
            auto j = pq1.top(); pq1.pop();
            upd(j.first + 1, 1); upd(rangs[j.second].second + 2, -1);
            used[j.second] = 1;
        }
    }
    for (int i = 0; i < rangs.size(); i++) {
        if (used[i]) continue;
        rangs2[rangs[i].first].push_back(rangs[i].second);
    }
    priority_queue<int> pq2;
    vector<int> memans(uv.size() + 1, N + 2);
    if (!die) memans[0] = 0;
    int ans2 = 0;
    for (int i = 0; i < uv.size() && !die; i++) {
        for (int j : rangs2[i]) pq2.push(j);
        while (qry(i + 1) < 0) {
            if (pq2.empty()) {
                die = 1;
                break;
            }
            ans2++;
            int j = pq2.top(); pq2.pop();
            upd(i + 1, 1); upd(j + 2, -1);
        }
        if (!die) memans[i + 1] = ans2;
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> a >> b;
        a = lower_bound(uv.begin(), uv.end(), a) - uv.begin();
        b = lower_bound(uv.begin(), uv.end(), b) - uv.begin();
        int res = min(memans[a], memans[b] + 1);
        cout << (res >= N + 2 ? -1 : N + 1 - res - ans1) << '\n';
    }
}
