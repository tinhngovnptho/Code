/*
	Author: tinhnopro
	created: 2025.04.08 14:08:30
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 10
#endif // LOCAL

using namespace std;

using i64 = long long;

template <typename T>  bool maximize(T &a, const T &b) { return a < b ? a = b, true : false; }
template <typename T>  bool minimize(T &a, const T &b) { return a > b ? a = b, true : false; }
#if __cplusplus < 202002L
	template <class T> int ssize(const T &a) { return a.size(); }
#endif
//_____________________________________________________________________________________________

const int MOD = 1e9 + 7; 

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD; 
}

int mul(int a, int b) {
	i64 res = 1LL * a * b; 
	return res % MOD; 
}

int Pow(int a, i64 b) {
	int res = 1; 
	for (; b; b >>= 1LL, a = mul(a, a)) if (b & 1LL) res = mul(res, a);
	return res; 
}

struct Matrix {
		vector<vector<int>> mat;
		int r, c;

		Matrix(int r = 0, int c = 0): r(r), c(c), mat(r, vector<int>(c, 0)) {}
		Matrix(vector<vector<int>> mat): r(mat.size()), c(mat[0].size()), mat(mat) {}

		Matrix operator *(const Matrix &ot) const {
				Matrix res(r, ot.c);
				for (int i = 0; i < r; ++i)
					for (int j = 0; j < c; ++j) {
						for (int k = 0; k < c; ++k) add(res.mat[i][j], mul(mat[i][k], ot.mat[k][j]));
				}
				return res;
		}
		Matrix pow(i64 b) const {
				Matrix res(r, c), a = *this;
				for (int i = 0; i < r; ++i) res.mat[i][i] = 1;
				for (; b; b >>= 1LL, a = a * a) if (b & 1LL) res = res * a;
				return res;
		}
};

int n, x, k; 

void tinhnop() {
	cin >> n >> x >> k; 
	int ans = mul(Pow(2 * k + 1, n - 1), x + k);
	
	Matrix mat(x, x);
	Matrix res(x, x);

	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < x; ++j) {
			mat.mat[i][j] = abs(i - j) <= k;
		}
	}

	res = mat.pow(n - 1);

	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < x; ++j) {
			ans = (ans - res.mat[i][j] + MOD) % MOD;
		}
	}

	cout << ans << '\n';
}

//_____________________________________________________________________________________________
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	#define cherry "bseq"
	if (fopen(cherry".inp", "r")) {
		freopen(cherry".inp", "r", stdin);
		freopen(cherry".out", "w", stdout);
	}

	int Ntest; cin >> Ntest; while (Ntest--)
	tinhnop();

	cerr <<"\n[runtime] " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.";
	return 0;
}