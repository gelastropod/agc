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
        int N, a, ans = 1; cin >> N;
        vector<int> A;
        for (int i = 0; i < N; i++) {
            cin >> a;
            A.push_back(a);
        }
        sort(A.begin(), A.end());
        for (int i = 1; i < N; i++) A[i] += A[i - 1];
        for (int i = N - 2; i >= 0; i--) {
            if (A[i + 1] > 3 * A[i]) {
                cout << ans << '\n';
                return 0;
            }
            ans++;
        }
        cout << ans << '\n';
}
