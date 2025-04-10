/*
	Author: tinhnopro
	created: 03.04.2025 14:58:19
*/
#include <bits/stdc++.h>

#define CHERRY "notes"

using namespace std;

using i64 = long long;

const int maxN = 1e6 + 5; 

struct Edge {
	int u, v, w; 
	Edge() {
		u = v = w = 0; 
	}

	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

struct DSU {
	int lab[maxN]; 

	DSU() {
		memset(lab, -1, sizeof(lab)); 
	}

	int find_par(int u) {
		return lab[u] < 0 ? u : lab[u] = find_par(lab[u]); 
	}

	bool join(int u, int v) {
		u = find_par(u);
		v = find_par(v); 

		if (u == v) return false; 

		if (lab[u] > lab[v]) swap(u, v); 
		lab[u] += lab[v]; 
		lab[v] = u; 
		return true; 
	}
} dsu;

int n; 
vector<Edge> edges; 

bool cmp(const Edge &a, const Edge &b) {
	return a.w < b.w; 
}


void solve() {
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int x; cin >> x; 
			if (i != j) {
				edges.push_back({i, j, x});
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		int x; cin >> x; 
		edges.push_back({0, i, x});
	}


	sort(edges.begin(), edges.end(), cmp); 

	i64 res = 0; 

	// vector<Edge> mst;

	for (int i = 0; i < (int) edges.size(); ++i) {
		if (dsu.join(edges[i].u, edges[i].v)) {
			res += edges[i].w;
			// mst.push_back(edges[i]);
		}
	}

	// for (Edge x : mst) cout << x.u << ' ' << x.v << ' ' << x.w << '\n';
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