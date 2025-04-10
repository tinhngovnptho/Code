/*
	Author: tinhnopro
	created: 04.04.2025 14:07:35
*/
#include <bits/stdc++.h>

#define CHERRY "product"

using namespace std;

using i64 = long long;

const int maxN = 1e5 + 5; 

int n, a[maxN], dp[maxN][2]; 

void solve() {
	cin >> n; 
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	dp[1][0] = abs(a[1] + 1); 
	dp[1][1] = abs(a[1] - 1);

	for (int i = 2; i <= n; ++i) {
		dp[i][0] = min(dp[i - 1][0] + abs(a[i] - 1), dp[i - 1][1] + abs(a[i] + 1));
		dp[i][1] = min(dp[i - 1][0] + abs(a[i] + 1), dp[i - 1][1] + abs(a[i] - 1));
	}

	cout << dp[n][1];
	
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