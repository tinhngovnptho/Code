/*
	Author: tinhnopro
	created: 2025.04.08 15:27:36
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

int n, m; 
i64 k; 
string f[20];

void tinhnop() {
	cin >> n >> k >> m;

	f[0] = "0"; 
	f[1] = "1"; 

	for (int i = 2; i <= n; ++i) {
		f[i] = f[i - 2] + f[i - 1];
	}

	vector<string> v; 

	string c = "";

	for (int i = ssize(f[n]) - 1; ~i; --i) {
		c = f[n][i] + c; 
		v.push_back(c); 
	}

	sort(v.begin(), v.end()); 

	for (string x : v) cout << x << '\n';

	for (int i = 0; i < min(m, ssize(v[k - 1])); ++i) cout << v[k - 1][i];
}

//_____________________________________________________________________________________________
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	#define cherry "sfibo"
	if (fopen(cherry".inp", "r")) {
		freopen(cherry".inp", "r", stdin);
		freopen(cherry".out", "w", stdout);
	}

	// int Ntest; cin >> Ntest; while (Ntest--)
	tinhnop();

	cerr <<"\n[runtime] " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.";
	return 0;
}