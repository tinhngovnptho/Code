/*
	Author: tinhnopro
	created: 04.04.2025 14:36:44
*/
#include <bits/stdc++.h>

#define CHERRY "maze"

using namespace std;

using i64 = long long;

const int maxN = 105; 

int n, m; 
int c[maxN][maxN], d[maxN][maxN], dist[maxN][maxN][20]; 

int en_i, en_j;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char mark[] = {'C', 'N', 'P', 'Z'};

void dfs(int x, int y, int mask) {
	if (x == en_i && y == en_j) return ; 

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i]; 
		int ny = y + dy[i]; 

		if (1 > nx || nx > n || 1 > ny || ny > m) continue;
		
		
		int color; 

		if (i < 2) {
			int d_idx = x; 
			if (i == 1) {
				d_idx--; 	
			}
			color = d[d_idx][y];
		} else {
			int c_idx = y; 
			if (i == 3) {
				c_idx--; 
			}
			color = c[x][c_idx];
		}
		
		if (~dist[nx][ny][(1 << color) | mask]) continue;

		dist[nx][ny][(1 << color) | mask] = dist[x][y][mask] + 1; 

		dfs(nx, ny, (1 << color) | mask);
	}
}

void solve() {
	cin >> n >> m; 
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < m; ++j) {
			char ch; cin >> ch; 
			for (int dr = 0; dr < 4; ++dr) if (mark[dr] == ch) {
				c[i][j] = dr; 
				break;
			}
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char ch; cin >> ch;
			for (int dr = 0; dr < 4; ++dr) if (mark[dr] == ch) {
				d[i][j] = dr; 
				break; 
			}  
		}
	}

	int q; 
	cin >> q; 
	while (q--) {
		int x, y;
		cin >> x >> y >> en_i >> en_j;

		memset(dist, -1, sizeof(dist));
		dfs(x, y, 0);

		int ans = 4;

		for (int mask = 0; mask < (1 << 4); ++mask) {
			if (~dist[en_i][en_j][mask]) {
				ans = min(ans, __builtin_popcount(mask));
			}
		}

		cout << ans << '\n'; 
	}

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