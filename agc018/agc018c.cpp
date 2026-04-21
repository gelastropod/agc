#include <bits/stdc++.h>
using namespace std;
#define int long long

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.first.first - a.first.second < b.first.first - b.first.second;
}

signed main() {
    int X, Y, Z, a, b, c, csum = 0;
    cin >> X >> Y >> Z;
    vector<pair<pair<int, int>, int>> vals;
    for (int i = 0; i < X + Y + Z; i++) {
        cin >> a >> b >> c;
        vals.push_back({{a - c, b - c}, c});
        csum += c;
    }
    sort(vals.begin(), vals.end(), comp);
    vector<int> sv(X + Y + Z, 0), gv(X + Y + Z, 0);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < Y; i++) {
        pq.push(vals[i].first.second);
        sv[Y - 1] += vals[i].first.second;
    }
    for (int i = Y; i < X + Y + Z; i++) {
        pq.push(vals[i].first.second);
        sv[i] = sv[i - 1] - pq.top() + vals[i].first.second;
        pq.pop();
    }
    while (pq.size()) pq.pop();
    for (int i = 0; i < X; i++) {
        pq.push(vals[X + Y + Z - 1 - i].first.first);
        gv[Y + Z] += vals[X + Y + Z - 1 - i].first.first;
    }
    for (int i = X; i < X + Y + Z; i++) {
        pq.push(vals[X + Y + Z - 1 - i].first.first);
        gv[X + Y + Z - 1 - i] = gv[X + Y + Z - i] - pq.top() + vals[X + Y + Z - 1 - i].first.first;
        pq.pop();
    }
    int added = LLONG_MIN;
    for (int i = Y - 1; i < Y + Z; i++)
        added = max(added, sv[i] + gv[i + 1]);
    cout << csum + added << '\n';
}
