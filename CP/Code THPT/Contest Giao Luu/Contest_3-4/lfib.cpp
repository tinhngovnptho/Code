/*
	Author: tinhnopro
	created: 03.04.2025 13:58:28
*/
#include <bits/stdc++.h>

#define CHERRY "lfib"

using namespace std;

using i64 = long long;

const int base = 1000000000;
const int base_digits = 9;


struct bigint {
	vector<int> a;
	int sign;

	bigint() :
			sign(1) {
	}

	bigint(long long v) {
			*this = v;
	}

	bigint(const string &s) {
			read(s);
	}

	void operator=(const bigint &v) {
			sign = v.sign;
			a = v.a;
	}

	void operator=(long long v) {
			sign = 1;
			if (v < 0)
					sign = -1, v = -v;
			for (; v > 0; v = v / base)
					a.push_back(v % base);
	}

	bigint operator+(const bigint &v) const {
					bigint res = v;

					for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) | carry; ++i) {
							if (i == (int) res.a.size())
									res.a.push_back(0);
							res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
							carry = res.a[i] >= base;
							if (carry)
									res.a[i] -= base;
					}
					return res;
	}


	bool operator<(const bigint &v) const {
			if (sign != v.sign)
					return sign < v.sign;
			if (a.size() != v.a.size())
					return a.size() * sign < v.a.size() * v.sign;
			for (int i = a.size() - 1; i >= 0; i--)
					if (a[i] != v.a[i])
							return a[i] * sign < v.a[i] * sign;
			return false;
	}

	bool operator>(const bigint &v) const {
			return v < *this;
	}
	bool operator<=(const bigint &v) const {
			return !(v < *this);
	}
	bool operator>=(const bigint &v) const {
			return !(*this < v);
	}
	bool operator==(const bigint &v) const {
			return !(*this < v) && !(v < *this);
	}
	bool operator!=(const bigint &v) const {
			return *this < v || v < *this;
	}

	void trim() {
			while (!a.empty() && !a.back())
					a.pop_back();
			if (a.empty())
					sign = 1;
	}

	bool isZero() const {
			return a.empty() || (a.size() == 1 && !a[0]);
	}

	void read(const string &s) {
			sign = 1;
			a.clear();
			int pos = 0;
			while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
					if (s[pos] == '-')
							sign = -sign;
					++pos;
			}
			for (int i = s.size() - 1; i >= pos; i -= base_digits) {
					int x = 0;
					for (int j = max(pos, i - base_digits + 1); j <= i; j++)
							x = x * 10 + s[j] - '0';
					a.push_back(x);
			}
			trim();
	}

};

bigint fib[450];

void solve() {
	int t; 
	cin >> t; 

	fib[0] = 0;
	fib[1] = 1; 
	for (int i = 2; i < 402; ++i) {
		fib[i] = fib[i - 1] + fib[i - 2];

		// for (int x : fib[i].a) cout << x; 
		// cout << '\n';
	}

	while (t--) {
		int i, j; 
		string s;
		cin >> i >> j >> s;
		bigint t(s); 
		if (fib[i] + fib[j] == s) {
			cout << "YES\n";
		} else cout << "NO\n";
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