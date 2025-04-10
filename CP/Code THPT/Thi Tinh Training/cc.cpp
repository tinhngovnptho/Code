#include <bits/stdc++.h>

using namespace std;

#define TASK ""

typedef long long i64;

const int maxN = 2009;

int S, n, dp[maxN];
vector<pair<int, int> > List[maxN];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}


	cin >> S >> n;
	for (int i = 1, v, w, a; i <= n; ++i) {
		cin >> v >> w >> a;
		List[w].push_back({v, a});
	}

	for (int w = 1; w <= S; ++w) {
		if (List[w].empty()) continue;
		sort(List[w].begin(), List[w].end(), greater<pair<int, int> >());

		for (int step = 1, idx = 0, cur = List[w][0].second; step <= S / w; ++step) {
			for (int c = S; c >= w; --c) {
				dp[c] = max(dp[c], dp[c - w] + List[w][idx].first);
			}

			if (step >= cur) {
				idx++;

				if (idx >= int(List[w].size())) break;

				cur += List[w][idx].second;
			}
		}
	}

	cout << dp[S];
}
