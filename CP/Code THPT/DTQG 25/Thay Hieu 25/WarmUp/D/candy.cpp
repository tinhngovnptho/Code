#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define BIT(x, i) ((x) & (1 << (i)))
#define MASK(x) (1 << (x))
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORDE(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

const int MAXN = 5e5 + 11, MAX = 1e6 + 11;
const int MOD = 1e9 + 7;
//const int INF = 1e9 + 11;

int n, k;
int f[11][MAXN];

void add(int &a, int b) {
    ll res = (a + b) % MOD;
    a = res % MOD;
}

void process(void) {
    cin >> n >> k;
    f[0][0] = 1;
    FORE(i, 1, k) FORE(t, 1, n) {
        add(f[i][t], f[i - 1][t - i] + f[i][t - i]);
    }
    cout << f[k][n];
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("candy");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
