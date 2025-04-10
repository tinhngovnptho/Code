/*
	Author: tinhnopro
	created: 13.03.2025 14:12:12
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif // LOCAL

#define TASK "cake"

using namespace std;

using i64 = long long;
#define int long long 

const int maxN = 2009; 

int n, k, p; 
int a[maxN], b[maxN], dp[maxN][maxN];

namespace Sub1 {

	void Main() {
		vector<int> v;

		int ans = 1e9 + 9; 

		for (int mask = 1; mask < (1 << k); ++mask) {
			v.clear(); 
			if (__builtin_popcount(mask) == n) {
				for (int i = 1; i <= k; ++i) if ((mask >> (i - 1)) & 1) {
					v.push_back(b[i]);
				}

				int res = 0; 

				for (int i = 1; i <= n; ++i) {
					res = max(res, abs(a[i] - v[i - 1]) + abs(p - v[i - 1]));
				}

				ans = min(ans, res); 

				while (next_permutation(v.begin(), v.end())) {
					for (int i = 1; i <= n; ++i) {
						res = max(res, abs(a[i] - v[i - 1]) + abs(p - v[i - 1]));
					}
					
					ans = min(ans, res); 
				}
			}
		}

		cout << ans; 
	}

	bool run() {
		if (k > 6) return false; 
		return Main(), true;
	}
}


int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	cin >> n >> k >> p; 
	for (int i = 1; i <= n; ++i) {
		cin >> a[i]; 
	}

	
	for (int i = 1; i <= k; ++i) {
		cin >> b[i];
	}
	
	if (Sub1::run()) return 0; 

	sort(a + 1, a + n + 1); 
	sort(b + 1, b + k + 1);

	memset(dp, 0x3f, sizeof(dp));

	dp[0][0] = 0;

	for (int j = 1; j <= k; ++j) {
		for (int i = 1; i <= n; ++i) {
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]); 
			dp[i][j] = min(dp[i][j], max(dp[i - 1][j - 1], abs(a[i] - b[j]) + abs(p - b[j])));
		}
	}

	cout << dp[n][k]; 
}