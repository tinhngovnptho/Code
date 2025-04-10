/*
	Author: tinhnopro
	created: 27.03.2025 14:08:07
*/
#include <bits/stdc++.h>

#define CHERRY "lamps"

using namespace std;

using i64 = long long;

void solve() {
	int t; 
	cin >> t; 

	while (t--) {
		int n, m; 
		cin >> n >> m; 

		int col = (int)sqrt(n);
		int row = (int)sqrt(m); 

		// cout << col << ' ' << row << '\n';

		cout << (i64) 1LL * col * (m - row) + 1LL * row * (n - col) << '\n'; 
	}
	
	return void(cout << '\n');
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(CHERRY".inp", "r")) {
		freopen(CHERRY".inp", "r", stdin);
		freopen(CHERRY".out", "w", stdout);
	}

	unsigned testcases = 1; 
	// cin >> testcases;

	for (unsigned test = 1; test <= testcases; ++test) {
		cerr << "Case #" << test << '\n';
		solve();
	}

	cerr << "[runtime] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";

	return 0; 
}