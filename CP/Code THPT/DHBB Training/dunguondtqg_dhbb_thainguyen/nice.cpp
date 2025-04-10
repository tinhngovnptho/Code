/*
	Author: tinhnopro
	created: 04.04.2025 14:18:45
*/
#include <bits/stdc++.h>

#define CHERRY "nice"

using namespace std;

using i64 = long long;

const int maxN = 1e5 + 5; 

int n, dp[maxN], a[maxN], max_dp[maxN];

void solve() {
	cin >> n; 
	for (int i = 1; i <= n; ++i) {
		cin >> a[i]; 
	}

	for (int i = n - 1; i >= 1; --i) {
		if (i + a[i] <= n) {
			dp[i] = max_dp[i + a[i] + 1] + (a[i] + 1); 
		} else dp[i] = 0;
		max_dp[i] = max(max_dp[i + 1], dp[i]);
	}

	cout << n - max_dp[1];

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