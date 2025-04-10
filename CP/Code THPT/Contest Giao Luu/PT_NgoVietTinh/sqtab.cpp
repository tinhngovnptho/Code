/*
	Author: tinhnopro
	created: 03.04.2025 14:41:48
*/
#include <bits/stdc++.h>

#define CHERRY "sqtab"

using namespace std;

using i64 = long long;

int n;
i64 k; 

i64 cnt(i64 x) {
	i64 res = 0; 
	for (i64 i = 1; i <= n; ++i) {
		if (x >= i * i) {
			res += min(1LL * n, (i64)sqrtl(x - i * i));
		}
	}
	return res; 
}

void solve() {
	cin >> n >> k; 
	
	i64 lo = 2, hi = 1e14, res = -1; 

	while (lo <= hi) {
		i64 mid = (lo + hi) / 2; 
		if (cnt(mid) >= k) {
			res = mid; 
			hi = mid - 1; 
		} else lo = mid + 1; 
	}

	cout << res; 

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