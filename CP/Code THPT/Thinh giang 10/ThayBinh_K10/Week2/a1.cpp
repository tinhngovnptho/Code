/*
	Author: tinhnopro
	created: 2025.04.08 12:19:19
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 10
#endif // LOCAL

using namespace std;

using i64 = long long;

template <typename T>  bool maximize(T &a, const T &b) { return a < b ? a = b, true : false; }
template <typename T>  bool minimize(T &a, const T &b) { return a > b ? a = b, true : false; }
#if __cplusplus < 202002L
	template <class T> int ssize(const T &a) { return a.size(); }
#endif
//_____________________________________________________________________________________________

const int maxN = 3e5 + 5; 

int n, m;
vector<int> adj[maxN]; 
int low[maxN], num[maxN], joint[maxN], ccs[maxN]; 

void dfs(int u, int par) {
	static int timeDFS = 0; 
	int child = 1; 

	low[u] = num[u] = ++timeDFS; 

	ccs[u] = (u != par);

	for (int v : adj[u]) if (v != par) {
		if (!num[v]) {
			dfs(v, u); 
			
			minimize(low[u], low[v]);
			child++; 

			if (low[v] >= num[u]) ccs[u]++;
			
			if (u == par) {
				if (child > 1) joint[u] = true; 
			} else if (low[v] >= num[u]) joint[u] = true; 

		} else minimize(low[u], num[v]);
	}
}

void dfs2(int u) {
	num[u] = 1; 
	for (int v : adj[u]) {
		if (!num[v]) dfs2(v);
	}
}

void tinhnop() {
	cin >> n >> m; 
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v; 
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) if (!num[i]) dfs(i, i);

	int ans = 0, res = 0;
	memset(num, 0, sizeof(num));
	for (int i = 1; i <= n; ++i) if (!num[i]) {
		ans++;
		dfs2(i);
	} 

	int cmax = -1;

	for (int i = 1; i <= n; ++i) if (joint[i]) {
		if (maximize(cmax, ccs[i])) res = i; 
	}

	ans += cmax - 1; 

	cout << ans << ' ' << res << '\n';
}

//_____________________________________________________________________________________________
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	#define cherry "a1"
	if (fopen(cherry".inp", "r")) {
		freopen(cherry".inp", "r", stdin);
		freopen(cherry".out", "w", stdout);
	}

	// int Ntest; cin >> Ntest; while (Ntest--)
	tinhnop();

	cerr <<"\n[runtime] " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.";
	return 0;
}