// tinhnopro 
#include <bits/stdc++.h>
using namespace std; 

#define hanh "rectangle"

using i64 = long long;

const int maxN = 7e4 + 4;

int n, x[maxN], y[maxN];


namespace Sub12 {
	map<pair<int, int>, int> cnt; 
	vector<int> crod[maxN];

	void Main() {
		for (int i = 1; i <= n; ++i) {
			crod[x[i]].push_back(y[i]);
		}
	
		for (int i = 1; i < maxN; ++i) {
			if ((int)crod[i].size() < 2)	{
				continue;
			}
			sort(crod[i].begin(), crod[i].end());
		}
	
		i64 ans = 0; 
	
		for (int i = 0; i < maxN; ++i) {
			if ((int)crod[i].size() < 2) continue;
	
			for (size_t j = 0; j < crod[i].size(); ++j) {
				for (size_t j2 = j + 1; j2 < crod[i].size(); ++j2) {
					ans += cnt[{crod[i][j], crod[i][j2]}];
				}
			}
	
			for (size_t j = 0; j < crod[i].size(); ++j) {
				for (size_t j2 = j + 1; j2 < crod[i].size(); ++j2) {
					cnt[{crod[i][j], crod[i][j2]}]++;
				}
			}
		}
	
		cout << ans; 
	}

	bool run() {
		if (n > 2000) return false; 
		return Main(), true;
	}
}

namespace Subfull {
	const int mx = 1e5 + 5; 

	vector<int> crod[mx], bl1, bl2, small[mx];
	int mark[mx], cnt[mx];

	const int BLOCK = 316; 

	void Main() {
		for (int i = 1; i <= n; ++i) {
			crod[x[i]].push_back(y[i]);
		}
	
		for (int i = 0; i < mx; ++i) {
			if ((int)crod[i].size() < 2)	{
				continue;
			}
			sort(crod[i].begin(), crod[i].end());
			if (crod[i].size() <= BLOCK) bl1.push_back(i);
			else bl2.push_back(i);

		}
	
		i64 ans = 0; 
		// calc bl1
		for (int x : bl1) {
			for (size_t i = 0; i < crod[x].size(); ++i) {
				for (size_t j = i + 1; j < crod[x].size(); ++j) {
					small[crod[x][i]].push_back(crod[x][j]);
				}
			}	
		}

		for (int i = 0; i < mx; ++i) {
			for (int x : small[i]) cnt[x]++; 
			for (int x : small[i]) if (cnt[x]) {
				ans += 1LL * cnt[x] * (cnt[x] - 1) / 2; 
				cnt[x] = 0;
			}
		}

		// calc bl2

		for (size_t i = 0; i < bl2.size(); ++i) {
			int x = bl2[i]; 
			for (int j : crod[x]) mark[j] = 1; 
			
			for (size_t j = i + 1; j < bl2.size(); ++j) {
				int x2 = bl2[j];
				i64 cnt = 0;
				for (int j : crod[x2]) if (mark[j]) cnt++; 
				
				ans += cnt * (cnt - 1) / 2; 
			}

			for (int j : crod[x]) mark[j] = 0; 
		}

		// calc bl1 bl2
		
		for (int x : bl2) {
			for (int j : crod[x]) mark[j] = 1; 
			for (int x2 : bl1) {
				i64 cnt = 0; 
				for (int j : crod[x2]) cnt += mark[j];
				
				ans += cnt * (cnt - 1) / 2;
			}

			for (int j : crod[x]) mark[j] = 0; 
		}
		
	
		cout << ans; 
	}

	bool run() {

		return Main(), true;
	}
}



void Input() {
	cin >> n; 
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i]; 
	}
}

void Main() {
	// if (Sub12::run()) return ;
	Subfull::run(); 
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