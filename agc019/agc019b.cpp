#pragma GCC optimize("O3,inline")
#include <iostream>
#include <vector>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    vector<int> freq(26, 0);
    for (char i : s) freq[i - 'a']++;
    int n = s.size();
    int ans = (n * (n - 1)) / 2 + 1;
    for (int i : freq) ans -= (i * (i - 1)) / 2;
    cout << ans << '\n';
}
