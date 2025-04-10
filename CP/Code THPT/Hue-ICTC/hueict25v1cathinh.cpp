/*
	Author: tinhnopro
	created: 09.03.2025 09:44:26
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif // LOCAL

#define TASK ""

using namespace std;

using i64 = long long;

const int maxN = 2000; 

int n, m, x[maxN], y[maxN]; 
int cnt[4]; 

void part(int x) {
	
	if (x <= n + 1) {
		cnt[0]++;
		if (x == n + 1) cnt[1]++; 
		if (x == 1) cnt[3]++; 
		return ;
	} 

	if (x <= 2 * n + 1) {
		cnt[1]++; 
		if (x == 2 * n + 1) cnt[2]++; 
		return ; 
	}

	if (x <= 3 * n + 1) {
		cnt[2]++; 
		if (x == 3 * n + 1) cnt[3]++;
		return ; 
	}

	cnt[3]++;  
}

bool check_cut(pair<int, int> x, pair<int, int> y) {
	part(x.first); 
	part(x.second); 
	part(y.first); 
	part(y.second); 

	int ret = 0; 
	for (int i = 0; i < 4; ++i) if (cnt[i] == 0) ret++;
	
	for (int i = 0; i < 4; ++i) cnt[i] = 0; 

	if (ret == 0) return true;
	 

}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	cin >> n >> m; 

	set<pair<int, int> > s; 

	for (int i = 1; i <= m; ++i) {
		cin >> x[i] >> y[i]; 
		if (x[i] > y[i]) swap(x[i], y[i]);
		s.insert({x[i], y[i]});
	}

	int ans = s.size() + 1;
	
	vector<pair<int, int> > v(s.begin(), s.end()); 

	for (int i = 0; i < (int) v.size(); ++i) {
		for (int j = i + 1; j < (int) v.size(); ++j) {
			if (check_cut(v[i], v[j])) ans++; 
		}
	}

	cout << ans; 
}