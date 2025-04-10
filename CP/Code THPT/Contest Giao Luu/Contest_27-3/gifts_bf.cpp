/*
	Author: tinhnopro
	created: 27.03.2025 14:17:45
*/
#include <bits/stdc++.h>

#define CHERRY "gifts"

using namespace std;

using i64 = long long;
#define int long long 

const int maxN = 1e5 + 5; 

int n, m, k; 
int a[maxN];

namespace Sub1 {
	int b[maxN]; 
	void Main() {
		sort(a + 1, a + n + 1);
		
		int ans = 0;

		for (int i = 1; i <= n - k + 1; ++i) {
			int res = 0, cnt = 0;
			bool check = true; 
			for (int j = 1; j < i; ++j) {
				res += a[j]; 
				if (res > m) {
					res -= a[i];
					check = false; 
					break; 
				}
				++cnt;
			}

			if (!check) {
				ans = max(ans, cnt); 
				break;
			}
			
			for (int j = i; j <= i + k - 1; ++j) {
				res += a[j] / 2;
				if (res > m) {
					break;
				}
				cnt++;
			}  

			// cout << i << ' ' << res << ' ' << cnt << '\n';
			ans = max(ans, cnt); 
		}

		cout << ans;
	}

	bool run() {
		if (n > 1000) return false; 
		return Main(), true;
	}
}

namespace Sub2 {

	i64 sum[maxN]; 

	void Main() {
		sort(a + 1, a + n + 1);

		for (int i = 1; i <= n; ++i) {
			sum[i] = sum[i - 1] + a[i]; 
		}

		int ans = 0; 

		for (int i = 1; i <= n - k + 1; ++i) {
			i64 res = sum[i - 1]; 
			if (res > m) break; 
			int l = i, r = i + k - 1, pos; 
			while (l <= r) {
				int mid = (l + r) >> 1; 
				if ((sum[mid] - sum[i - 1]) / 2 + res <= m) {
					pos = mid; 
					l = mid + 1; 
				} else r = mid - 1; 
			}

			ans = max(ans, pos);
		}

		cout << ans; 
	}

	bool run() {

		return Main(), true;
	}
}



void solve() {
	cin >> n >> m >> k; 
	for (int i = 1; i <= n; ++i) {
		cin >> a[i]; 
	}	

	if (Sub1::run()) return ;
	// if(Sub2::run()) return ;

	return void(cout << '\n');
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(CHERRY".inp", "r")) {
		freopen(CHERRY".inp", "r", stdin);
		freopen(CHERRY".ans", "w", stdout);
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