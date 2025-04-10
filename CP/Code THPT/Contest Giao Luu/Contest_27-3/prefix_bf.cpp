/*
	Author: tinhnopro
	created: 27.03.2025 15:16:22
*/
#include <bits/stdc++.h>

#define CHERRY "prefix"

using namespace std;

using i64 = long long;

const int maxN = 1e5 + 5; 

int n, f[maxN];

namespace Sub1 {

	int f_[10]; 

	void Main() {
		string ans;
		for (int i = 1; i <= n; ++i) ans.push_back('1');
		bool ok = false; 

		for (int mask = 0; mask < (1 << n); ++mask) {
			string s = "";
			for (int j = 0; j < n; ++j) {
				if ((mask >> j) & 1) s.push_back('1');
				else s.push_back('0');
			}

			f_[1] = f_[2] = 0; 

			for (int i = 3; i <= n; ++i) {
				for (int j = 1; j < i; ++j) {
					if (s.substr(0, j) == s.substr(i - j, j)) {
						f_[i] = j;
					}
				}
			}

			bool check = true;

			for (int i = 1; i <= n; ++i) {
				if (f[i] != f_[i]) {
					check = false;
					break; 
				}
			}

			if (check) {
				cout << s << '\n';
				ans = min(ans, s);
				ok = true; 
			}
		}

		if (!ok) cout << -1;
		else {
			for (int i = 0; i < n; ++i) {
				if (ans[i] == '0') cout << 'a'; 
				else cout << 'b'; 
			}
		}
	}

	bool run() {
		if (n > 7) return false; 
		return Main(), true;
	}
}

struct DSU {
	int lab[maxN]; 

	void init() {
		memset(lab, -1, sizeof(lab));
	}

	int find_par(int u) {
		return lab[u] < 0 ? u : lab[u] = find_par(lab[u]);
	}

	void join(int a, int b) {
		a = find_par(a); 
		b = find_par(b); 

		if (a == b) return ; 

		if (lab[a] > lab[b]) swap(a, b); 
		lab[a] += lab[b]; 
		lab[b] = a; 
	}
} dsu;

namespace Sub2 {
	int a[maxN]; 

	void Main() {
		dsu.init();
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= f[i]; ++j) {
				// cout << j << ' ' << i - f[i] + j << '\n';
				dsu.join(j, i - f[i] + j);
			}
		}

		int cnt = 0; 
		for (int i = 1; i <= n; ++i) {
			if (dsu.lab[i] < 0) cnt++;
		}

		if (cnt > 2) {
			cout << -1; 
			return ; 
		}	

		int idx = 0;

		for (int i = 1; i <= n; ++i) {
			if (dsu.lab[i] < 0) {
				idx = i; 
				break; 
			}		
		}

		for (int i = 1; i <= n; ++i) {
			if (i == idx || dsu.lab[i] == idx) {
				cout << 'a';
			} else cout << 'b'; 
		}
	}

	bool run() {

		return Main(), true;
	}
}



void solve() {
	cin >> n; 
	for (int i = 1; i <= n; ++i) cin >> f[i];

	if (Sub1::run()) return ; 
	// if (Sub2::run()) return ;

	return void(cout << '\n');
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(CHERRY".inp", "r")) {
		freopen(CHERRY".inp", "r", stdin);
		freopen(CHERRY".ans", "w", stdout);
	}

	unsigned testcases = 1; 
	// cin >> testcases;

	for (unsigned test = 1; test <= testcases; ++test) {
		cerr << "Case #" << test << '\n';
		solve();
	}

	cerr << "[runtime] " << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";

	return 0; 
}