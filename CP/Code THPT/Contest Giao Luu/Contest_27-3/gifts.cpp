/*
	Author: tinhnopro
	created: 30.03.2025 00:21:10
*/
#include <bits/stdc++.h>

#define CHERRY "gifts"

using namespace std;

using i64 = long long;

const int maxN = 1e5 + 5; 

int n, f[maxN];


void solve() {
	cin >> n; 
	for (int i = 1; i <= n; ++i) {
		cin >> f[i]; 
	}

	for 

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