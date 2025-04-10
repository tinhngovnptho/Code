/*
	Author: tinhnopro
	created: 13.03.2025 14:01:08
*/
#include <bits/stdc++.h>

#define TASK "demchan"

using namespace std;

using i64 = long long;
#define int long long 

const int maxN = 1e6 + 5;

int n, q; 
int a[maxN], cnt[maxN][2]; 

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	cin >> n >> q;  

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1); 

	for (int i = 1; i <= n; ++i) {
		cnt[i][0] += cnt[i - 1][0]; 
		cnt[i][1] += cnt[i - 1][1]; 

		cnt[i][a[i] % 2]++; 
	}

	int total = 0; 

	while (q--) {
		int type, op;

		cin >> type >> op;

		if (type == 1) {

			int v_ = op - total; 

			int t = lower_bound(a + 1, a + n + 1, v_) - a; 
			
			cout << cnt[t][total % 2] << '\n'; 

		} else {
			total += op; 
		}
	}
}	