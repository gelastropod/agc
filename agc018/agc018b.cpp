#pragma GCC optimize("O3,inline")
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, a, ans; cin >> N >> M;
    ans = N;
    vector<int> die(M, 0);
    vector<queue<int>> vals(N, queue<int>());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a; a--;
            vals[i].push(a);
        }
    }
    for (int i = 0; i < M; i++) {
        vector<int> freq(M, 0);
        for (int j = 0; j < N; j++) freq[vals[j].front()]++;
        //for (int j = 0; j < M; j++) cout << freq[j] << ' ';
        //cout << '\n';
        int crnt = 0, crntidx = -1;
        for (int j = 0; j < M; j++) {
            if (freq[j] <= crnt) continue;
            crntidx = j;
            crnt = freq[j];
        }
        //cout << crnt << ' ';
        ans = min(ans, crnt);
        //cout << ans << '\n';
        die[crntidx] = 1;
        for (int j = 0; j < N; j++) while (vals[j].size() && die[vals[j].front()]) vals[j].pop();
    }
    cout << ans << '\n';
}
