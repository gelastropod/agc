#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define MOD 998244353
#define HALF 499122177
#define SIZE 32768
#define LSIZE 15

int powm(int a, int b) {
	if (b == 0) return 1;
	if (b % 2) return (a * powm(a, b - 1)) % MOD;
	int res = powm(a, b / 2);
	return (res * res) % MOD;
}

vector<int> mem1, mem2;

int invm(int a) {
	return powm(a, MOD - 2);
}

int fact(int a) {
	if (mem1[a] != -1) return mem1[a];
	return mem1[a] = (a * fact(a - 1)) % MOD;
}

int ifact(int a) {
	if (mem2[a] != -1) return mem2[a];
	return mem2[a] = invm(fact(a));
}

vector<int> rou;

void comprou() {
	int crnt = 1, z = powm(3, (MOD - 1) / SIZE);
	for (int i = 0; i <= SIZE; i++) {
		rou.push_back(crnt);
		crnt *= z;
		crnt %= MOD;
	}
}

struct poly {
	vector<int> A;

	poly() : A(SIZE, 0) {}

	void eval(int mask, int n, queue<int>& vals) {
		if (n == LSIZE) {
			vals.push(A[mask]);
			return;
		}
		queue<int> a, b;
		eval(mask, n + 1, a); eval(mask + (1LL << n), n + 1, b);
		queue<int> res;
		for (int i = 0; i < SIZE / 2; i += (1LL << n)) {
			int pa = a.front(), pb = b.front();
			a.pop(); b.pop();
			vals.push((pa + rou[i] * pb) % MOD); res.push((pa - rou[i] * pb) % MOD);
		}
		while (res.size()) {
			vals.push(res.front());
			res.pop();
		}
	}

	void eval(queue<int>& vals) {
		eval(0, 0, vals);
	}

	static void coef(int mask, int n, queue<int>& vals, queue<int>& coefq) {
		if (n == LSIZE) {
			coefq.push(vals.front());
			vals.pop();
			return;
		}
		queue<int> split1, split2, val1, val2;
		queue<int> coef1, coef2;
		for (int i = 0; i < SIZE / 2; i += (1LL << n)) {
			split1.push(vals.front());
			vals.pop();
		}
		for (int i = 0; i < SIZE / 2; i += (1LL << n)) {
			split2.push(vals.front());
			vals.pop();
		}
		for (int i = 0; i < SIZE / 2; i += (1LL << n)) {
			int a = split1.front(), b = split2.front();
			split1.pop(); split2.pop();
			val1.push(((a + b) * HALF) % MOD); val2.push(((((a - b) * rou[SIZE - i]) % MOD) * HALF) % MOD);
		}
		coef(mask, n + 1, val1, coef1);
		coef(mask + (1LL << n), n + 1, val2, coef2);
		for (int i = 0; i < SIZE / 2; i += (1LL << n)) {
			coefq.push(coef1.front()); coefq.push(coef2.front());
			coef1.pop(); coef2.pop();
		}
	}

	poly(queue<int>& vals) {
		queue<int> coefq;
		coef(0, 0, vals, coefq);
		while (coefq.size()) {
			if ((int)A.size() < SIZE / 2) A.push_back(coefq.front());
			coefq.pop();
		}
		for (int i = 0; i < SIZE / 2; i++) A.push_back(0);
	}

	poly operator*(poly p) {
		queue<int> val1, val2;
		eval(val1); p.eval(val2);
		queue<int> vals;
		while (val1.size()) {
			vals.push((val1.front() * val2.front()) % MOD);
			val1.pop(); val2.pop();
		}
		return poly(vals);
	}

	void mod() {
		for (int i = 0; i < SIZE; i++) A[i] %= MOD;
	}

	poly pow(int a) {
		if (a == 0) {
			poly res;
			res.A[0] = 1;
			return res;
		}
		poly res;
		if (a % 2) res = operator*(pow(a - 1));
		else {
			res = pow(a / 2);
			res = res * res;
		}
		return res;
	}
};

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	comprou();
	mem1.resize(100000, -1);
	mem2.resize(100000, -1);
	mem1[0] = 1;
	string A, B; cin >> A >> B;
	int a = 0, b = 0;
	for (int i = 0; i < A.size(); i++) a += (A[i] == '1' && B[i] == '0'), b += (A[i] == '1' && B[i] == '1');
	poly p;
	for (int i = 0; i <= b; i++) p.A[i] = ifact(i + 1);
	poly res = p.pow(a);
	int ans = 0;
	for (int i = 0; i <= b; i++) ans += res.A[i], ans %= MOD;
	ans = (ans + MOD) % MOD;
	cout << (((((ans * fact(a)) % MOD) * fact(a + b)) % MOD) * fact(b)) % MOD << '\n';
}
