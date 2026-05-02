#pragma GCC optimize("O3,inline")
#include <iostream>
#include <bitset>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, a, sum = 0; cin >> N;
    bitset<4000001> bs = 1;
    for (int i = 0; i < N; i++) {
        cin >> a;
        sum += a;
        bs |= (bs << a);
    }
    int crnt = (sum + 1) / 2;
    while (1) {
        if (bs[crnt]) {
            cout << crnt << '\n';
            return 0;
        }
        crnt++;
    }
}
