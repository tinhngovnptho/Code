/*
	Author: tinhnopro
	created: 03.04.2025 15:51:43
*/
#include <bits/stdc++.h>

#define CHERRY "lfib"

using namespace std;

using i64 = long long;

int n = 30; 

i64 f[50];

void solve() {

	int t; cin >> t; 
	
	f[0] = 0; 
	f[1] = 1; 
	for (int i = 2; i <= n; ++i) f[i] = f[i - 1] + f[i - 2];

	while (t--) {
		int i, j; 
		i64 s;
		cin >> i >> j >> s; 

		if (f[i] + f[j] == s) {
			cout << "YES\n"; 
		} else cout << "NO\n";
	}
	
	return void(cout << '\n');
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	if (fopen(CHERRY".inp", "r")) {
		freopen(CHERRY".inp", "r", stdin);
		freopen(CHERRY".ans", "w", stdout);
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