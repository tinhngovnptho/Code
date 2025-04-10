/*
	Author: tinhnopro
	created: 13.03.2025 15:35:00
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif // LOCAL

#define TASK "bmh"

using namespace std;

using i64 = long long;

const int maxN = 1e5 + 5; 

int n, m, q, k; 

vector<int> adj[maxN]; 
vector<int> st;

int dist[maxN], vist[maxN]; 

void bfs() {
	queue<int> q; 

	memset(dist, 0x3f, sizeof(dist));

	for (int x : st) {
		q.push(x);  
		dist[x] = 0; 
		vist[x] = 1; 
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop(); 

		for (int v : adj[u]) if (!vist[v]) {
			dist[v] = dist[u] + 1;
			q.push(v);
			vist[v] = 1; 
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	cin >> n >> m >> q >> k; 

	for (int i = 1; i <= q; ++i) {
		int x; cin >> x; 
		st.push_back(x);
	}

	for (int i = 1; i <= m; ++i) {
		int u, v; 
		cin >> u >> v; 
		adj[u].push_back(v); 
		adj[v].push_back(u);
	}

	bfs(); 

	for (int i = 1; i <= n; ++i) {
		i64 x = (i64) sqrt(1LL * 2 * dist[i] / k); 
		if (x * (x + 1) < dist[i]) x++; 

		cout << x << ' '; 
	}
}