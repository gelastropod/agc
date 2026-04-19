#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define MOD 1000000007

struct vec {
	vector<int> data;

	vec(int A, int B, int C) : data{ A, B, C } {}
	vec() : data(3, 0) {}
};

struct mat {
	vector<int> data;
	
	mat(vector<int> _d) : data(_d) {}
	mat() : data(9, 0) {}

	static mat spec(int n) {
		if (n == 0) return mat({ 1, 0, 0, 0, 1, 0, 0, 0, 1 });
		if (n == 1) return mat({ 1, 0, 0, 1, 1, 0, 1, 2, 1 });
		if (n == 2) return mat({ 1, 0, 1, 1, 1, 1, 1, 2, 2 });
		return mat();
	}

	mat operator*(mat other) {
		mat res;
		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++) res.data[i * 3 + j] += data[i * 3 + k] * other.data[k * 3 + j];
		for (int i = 0; i < 9; i++) res.data[i] %= MOD;
		return res;
	}

	vec operator*(vec other) {
		vec res;
		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) res.data[i] += data[i * 3 + j] * other.data[j];
		for (int i = 0; i < 3; i++) res.data[i] %= MOD;
		return res;
	}

	mat pow(int n) {
		if (n == 0) return spec(0);
		if (n % 2 == 1) return operator*(pow(n - 1));
		mat res = pow(n / 2);
		return res * res;
	}
};

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M, x; cin >> N >> M;
	int crnt = 1;
	vec state(1, 1, 1);
	for (int i = 0; i < M; i++) {
		cin >> x;
		state = mat::spec(1) * mat::spec(2).pow(x - crnt) * state;
		crnt = x + 1;
	}
	state = mat::spec(2).pow(N - crnt) * state;
	cout << state.data[2] << '\n';
}
