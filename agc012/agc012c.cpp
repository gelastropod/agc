#include <cmath>

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N; N++;
    int p = log2(N), cnt = 100;
    vector<int> a;
    for (int i = 0; i < p; i++) {
        if (N & (1LL << i)) a.push_back(cnt--);
        a.push_back(i + 1);
    }
    cout << 2 * a.size() << '\n';
    for (int i = 0; i < p; i++) cout << i + 1 << ' ';
    for (int i = 0; i < a.size() - p; i++) cout << cnt + i + 1 << ' ';
    for (int i : a) cout << i << ' ';
    cout << '\n';
}

