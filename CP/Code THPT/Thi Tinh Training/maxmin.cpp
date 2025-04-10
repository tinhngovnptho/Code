/*
	Author: tinhnopro
	created: 04.01.2025 15:04:17
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif // LOCAL

#define TASK "maxmin"

using namespace std;

using i64 = long long;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}
    int n, x, y;
    cin >> n >> x >> y;
    set<int> xs, ys, bad;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == x) xs.insert(i);
        if (a == y) ys.insert(i);
        if (x < a) bad.insert(i);
        if (a < y) bad.insert(i);
    }

    i64 ans = 0;
    for (int l = 0; l < n; l++) {
        auto itb = bad.lower_bound(l);
        int bi = (itb == bad.end() ? n : *itb);

        auto itx = xs.lower_bound(l);
        if (itx == xs.end()) continue;
        if (*itx < l) continue;
        int xi = *itx;

        auto ity = ys.lower_bound(l);
        if (ity == xs.end()) continue;
        if (*ity < l) continue;
        int yi = *ity;

        int r = max(xi, yi);
        if (bi <= r) continue;
        ans += bi - r;
    }
    cout << ans << endl;
    return 0;
}