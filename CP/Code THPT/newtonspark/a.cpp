/*
	Author: tinhnopro
	created: 05.04.2025 08:31:23
*/
#include <bits/stdc++.h>

#define CHERRY ""

using namespace std;

using i64 = long long;

const int maxN = 2e6 + 5;
int isPrime[maxN], cnt[maxN];

void sieve() {
	memset(isPrime, -1, sizeof(isPrime));

	isPrime[0] = isPrime[1] = 0; 

	for (int i = 2; i * i < maxN; ++i) if (isPrime[i]) {
		for (int j = i * i; j < maxN; j += i) isPrime[j] = 0; 
	}

	for (int i = 2; i < maxN; ++i) {
		cnt[i] = cnt[i - 1];
		if (isPrime[i]) cnt[i]++;
	}
}

void solve() {
	sieve();
	int t; 
	cin >> t; 
	while (t--) {
		int k, p; 
		cin >> k >> p; 

		int d = cnt[p + k] - cnt[max(0, p - k - 1)];

		if (d) cout << 1; 
		else cout << 0; 
		cout << '\n';
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