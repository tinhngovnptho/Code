/*
	Author: tinhnopro
	created: 07.01.2025 07:30:45
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif // LOCAL

#define TASK "maze"

using namespace std;

using i64 = long long;

const int maxN = 1511; 
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const int inf = 1e9 + 5; 

int n, m;
char a[maxN][maxN]; 

queue<pair<int, int> > q; 
int dist[maxN][maxN], f[maxN][maxN];
bool vist[maxN][maxN]; 

vector<pair<int, int> > water; 

int xstart, ystart; 

bool inrange(const int& x, const int& y) {
	if (x < 1 || x > n) return false; 
	if (y < 1 || y > m) return false; 
	return true;
}

void build() {
	while (!q.empty()) q.pop();  

	memset(dist, 0x3f, sizeof(dist));

	for (auto w : water) {
		q.emplace(w.first, w.second); 
		dist[w.first][w.second] = 0;
		vist[w.first][w.second] = 1; 
	}

	while (!q.empty()) {
		int x, y; 
		tie(x, y) = q.front(); 
		q.pop(); 

		for (int i = 0; i < 4; ++i) {
			int xx = x + dx[i]; 
			int yy = y + dy[i]; 

			if (inrange(xx, yy) && !vist[xx][yy] && (a[xx][yy] == 'O')) {
				dist[xx][yy] = dist[x][y] + 1; 
				vist[xx][yy] = 1; 
				q.emplace(xx, yy);
			}
		}
	}
}

void getpath() {
	while (!q.empty()) q.pop();

	memset(vist, 0, sizeof(vist)); 
	memset(f, 0x3f, sizeof(f));

	q.emplace(xstart, ystart);
	vist[xstart][ystart] = 1; 
	f[xstart][ystart] = 0;
	
	while (!q.empty()) {
		int x, y; 
		tie(x, y) = q.front(); 
		q.pop(); 
		for (int i = 0; i < 4; ++i) {
			int xx = x + dx[i]; 
			int yy = y + dy[i]; 
			if (inrange(xx, yy) && !vist[xx][yy] && (a[xx][yy] == 'O') && (dist[xx][yy] > f[x][y]
			 + 1)) {
				f[xx][yy] = f[x][y] + 1; 
				vist[xx][yy] = 1; 
				q.emplace(xx, yy);
			}
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

	cin >> n >> m; 
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j]; 
			if (a[i][j] == 'S') water.emplace_back(i, j);
			if (a[i][j] == 'E') {
				xstart = i; 
				ystart = j; 
			}
		}
	}

	build();
	getpath(); 


	int ans = inf; 
	for (int i = 2; i < n; ++i) {
		if (a[i][1] == 'E' || a[i][m] == 'E') ans = 1; 
		if (f[i][1] > 0) ans = min(ans, f[i][1] + 1);
		if (f[i][m] > 0) ans = min(ans, f[i][m] + 1);
	}

	for (int i = 1; i <= m; ++i) {
		if (a[1][i] == 'E' || a[n][i] == 'E') ans = 1; 
		if (f[1][i] > 0) ans = min(ans, f[1][i] + 1); 
		if (f[n][i] > 0) ans = min(ans, f[n][i] + 1);
	}

	cout << (ans == inf ? -1 : ans);
}