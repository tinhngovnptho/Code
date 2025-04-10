/*
	Author: tinhnopro
	created: 03.04.2025 14:47:18
*/
#include <bits/stdc++.h>

#define CHERRY "mis"

using namespace std;

using i64 = long long;

const int maxN = 2e5 + 5; 

int n, a[maxN]; 

int cost(int x) {
	return x % 100; 
}

namespace Sub12 {

	int dp[maxN]; 

	void Main() {
		
		int ans = 0; 
		for (int i = 1; i <= n; ++i) {
			dp[i] = cost(a[i]); 
			for (int j = 1; j < i; ++j) if (a[j] < a[i]) {
				dp[i] = max(dp[i], dp[j] + cost(a[i]));
			}
			ans = max(ans, dp[i]);
		}

		cout << ans; 
	}

	bool run() {
		if (n > 2000) return false; 
		return Main(), true;
	}
}

namespace SubFull {

	int bit[maxN]; 

	const int mx = 1e5 + 5; 

	void update(int u, int val) {
		for (; u < mx; u += u & -u) bit[u] = max(bit[u], val);
	}

	int query(int u) {
		int res = 0; 
		for (; u; u -= u & -u) res = max(res, bit[u]);
		return res; 
	}

	void Main() {
		int ans = 0; 
		for (int i = 1; i <= n; ++i) {
			update(a[i], query(a[i] - 1) + cost(a[i]));
			ans = max(ans, query(a[i] - 1) + cost(a[i]));
		}

		cout << ans; 
	}

	bool run() {

		return Main(), true;
	}
}



void solve() {
	cin >> n; 
	for (int i = 1; i <= n; ++i) {
		cin >> a[i]; 
	}

	if (Sub12::run()) return ; 
	if (SubFull::run()) return ;

	return void(cout << '\n');
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	if (fopen(CHERRY".inp", "r")) {
		freopen(CHERRY".inp", "r", stdin);
		freopen(CHERRY".out", "w", stdout);
	}

	int t = 1; 
	// cin >> t;

	for (int i = 1; i <= t; ++i) {
		cerr << "Case #" << i << '\n';
		solve();
	}

	cerr << "[runtime] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";

	return 0; 
}