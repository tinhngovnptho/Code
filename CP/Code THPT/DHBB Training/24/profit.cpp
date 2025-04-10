// tinhnopro 
#include <bits/stdc++.h>
using namespace std; 

#define hanh "profit"

using i64 = long long;

const int maxN = 1e5 + 5;

int n, k, a[maxN];

pair<i64, int> dp[maxN][2];

void Input() {
	cin >> n >> k; 
	for (int i = 1; i <= n; ++i) {
		cin >> a[i]; 
	}
}

pair<i64, int> opt(i64 delta) {
	dp[1][0] = {0, 0}; 
	dp[1][1] = {-a[1] - delta, 1};

	for (int i = 2; i <= n; ++i) {
		dp[i][0] = max(dp[i - 1][0], make_pair(dp[i - 1][1].first + a[i], dp[i - 1][1].second));

		dp[i][1] = max(dp[i - 1][1], make_pair(dp[i][0].first - a[i] - delta, dp[i][0].second + 1));
	}

	return max(dp[n][1], dp[n][0]);
}

void Main() {
	i64 lo = 0;
	i64 hi = (i64) 1e18;

	while (hi - lo > 1) {
		i64 mid = (hi + lo) / 2;
		if (opt(mid).second >= k) lo = mid;
		else hi = mid;
	}

	cout << opt(lo).first + k * lo; 
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); 
	
	if (fopen(hanh".inp", "r")) {
		freopen(hanh".inp", "r", stdin); 
		freopen(hanh".out", "w", stdout);
	}

	int t = 1; 
	// cin >> t; 
	for (int i = 1; i <= t; ++i) {
		Input();
		Main();
	}

	cerr << "\n[runtime]" << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
	return 0; 
}