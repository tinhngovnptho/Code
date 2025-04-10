/*
	Author: tinhnopro
	created: 13.03.2025 14:28:02
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif // LOCAL

#define TASK "khoangcach"

using namespace std;

using i64 = long long;

const int maxN = 5e5 + 5; 

template<typename T> struct Compressor {
	vector<T> h; 

	void add(const T& x) {
		h.push_back(x);
	}

	void Compress() {
		sort(h.begin(), h.end()); 
		h.resize(unique(h.begin(), h.end()) - h.begin());
	}

	int Get(const T& x) {
		return lower_bound(h.begin(), h.end(), x) - h.begin() + 1; 
	}
};

int n, m;
int a[maxN];

int mark[maxN], last[maxN]; 
Compressor<int> com;

namespace Sub12 {

	void Main() {
		for (int i = 1; i <= m; ++i) {
			int l, r; 
			cin >> l >> r; 

			int res = maxN + 1; 

			for (int j = l; j <= r; ++j) {
				if (last[j] >= l) {
					res = min(res, j - last[j]);
				}
			}

			cout << (res == maxN + 1 ? -1 : res) << '\n'; 
		}
	}

	bool run() {
		if (n > 1000 || m > 1000) return false; 
		return Main(), true;
	}
}

namespace Subfull {

	struct query_t {
		int l, r, idx; 

		query_t(int _l = 0, int _r = 0, int _idx = 0) : l(_l), r(_r), idx(_idx) {}
	};

	vector<query_t> queries; 
	int c[maxN], ans[maxN], st[4 * maxN]; 

	void update(int id, int l, int r, int pos,  int val) {
		if (l > pos || pos > r) return ; 

		if (l == r) {
			st[id] = val; 
			return ; 
		}

		int mid = (l + r) >> 1; 

		update(id << 1, l, mid, pos, val); 
		update(id << 1 | 1, mid + 1, r, pos, val); 

		st[id] = min(st[id << 1], st[id << 1 | 1]); 
	}

	int getmin(int id, int l, int r, int u, int v) {
		if (l > v || r < u) return maxN + 1; 
		if (u <= l && r <= v) {
			return st[id];
		}

		int mid = (l + r) >> 1; 

		return min(getmin(id << 1, l, mid, u, v), getmin(id << 1 | 1, mid + 1, r, u, v));
	}

	void Main() {

		for (int i = 1; i <= m; ++i) {
			int l, r; 
			cin >> l >> r; 
			queries.push_back({l, r, i});
		}

		vector<pair<int, int> > d; 

		for (int i = 1; i <= n; ++i) {
			if (last[i] != 0) {
				d.push_back({i, last[i]}); 
			}
		}

		sort(d.begin(), d.end(), [](const pair<int, int> &a, const pair<int, int> &b){
			return a.second > b.second; 
		});

		sort(queries.begin(), queries.end(), [](const query_t &a, const query_t &b){
			if (a.l == b.l) return a.r < b.r; 
			return a.l < b.l; 
		}); 

		debug(d);

		for (int i = 1; i <= n; ++i) update(1, 1, n, i, maxN + 1); 

		for (pair<int, int> x : d) {
			update(1, 1, n, x.first, x.first - x.second);
		}

		for (query_t x : queries) {
			while (d.size() && d.back().second < x.l) {
				update(1, 1, n, d.back().first, maxN + 1);
				d.pop_back(); 
			}
			
			ans[x.idx] = getmin(1, 1, n, 1, x.r);
			if (ans[x.idx] == maxN + 1) ans[x.idx] = -1;
		}
		
		for (int i = 1; i <= m; ++i) cout << ans[i] << '\n';
	}

	bool run() {
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

	cin >> n >> m; 

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		com.add(a[i]);
	}

	com.Compress(); 

	for (int i = 1; i <= n; ++i) {
		a[i] = com.Get(a[i]); 

		last[i] = mark[a[i]]; 

		mark[a[i]] = i; 
	}
	
	if (Sub12::run()) return 0; 
	Subfull::run();
}