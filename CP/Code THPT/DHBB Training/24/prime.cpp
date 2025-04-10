/*
	Author: tinhnopro
	created: 27.03.2025 10:21:29
*/
#include <bits/stdc++.h>

#define CHERRY ""

using namespace std;

using i64 = long long;

const int maxN = 1e6 + 5; 

int prime[maxN], cnt[maxN]; 
vector<int> primes; 


void preprocess() {
	memset(prime, -1, sizeof(prime)); 
	prime[0] = prime[1] = 0; 

	for (int i = 2; i * i < maxN; ++i) if (prime[i]) {
		for (int j = i * i; j < maxN; j += i) prime[j] = 0; 
	}

	for (int i = 1; i < maxN; ++i) if (prime[i]) {
		primes.push_back(i); 
	}
}


void solve() {
	preprocess();

	int t; 
	cin >> t; 
	while(t--) {
		int n; 
		cin >> n;
		
		int key = sqrt(n); 
		
		int ans = 0; 

		for (int i = 0; i < (int)primes.size(); ++i) {
			if (primes[i] > key) break; 

			int d = n / primes[i]; 

			int j = upper_bound(primes.begin(), primes.end(), d) - primes.begin() - 1; 

			if (i == j) continue;

			ans = max(ans, primes[i] * primes[j]);
		}

		cout << ans << '\n';
	}

	return void(cout << '\n');
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(CHERRY".inp", "r")) {
		freopen(CHERRY".inp", "r", stdin);
		freopen(CHERRY".out", "w", stdout);
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