#include <bits/stdc++.h>

using namespace std;

#define el  "\n"
#define ll  long long
#define ull unsigned long long
#define pii pair<int, int>
#define vi  vector<int>
#define fi  first
#define se  second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define FORX(i, a, b, x) for (int i = (a), _b = (b); i <= _b; i += (x))
#define BIT(x, i) ((x) & (1LL << (i)))
#define MASK(x) (1LL << (x))
#define ONBIT(x, i) ((x) | (1LL << (i)))
#define OFFBIT(x, i) ((x) & ~(1LL << (i)))
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

const int MAXN = (int) 1e5 + 11;
//const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

struct Compress {
    vector<int> v;

    void add(int x) {
        v.push_back(x);
    }

    void init(void) {
        sort(ALL(v));
        v.resize(unique(ALL(v)) - v.begin());
    }

    int get(int x) const {
        return lower_bound(ALL(v), x) - v.begin() + 1;
    }
} zip;

int n, k, dp[MAXN], a[MAXN];
int seg[12 * MAXN];

#define Left(id) ((id) << 1)
#define Right(id) ((id) << 1 | 1)

void update(int id, int l, int r, int pos, int val) {
    if (l > pos || pos > r) return ;
    if (l == r) {
        seg[id] = val;
        return ;
    }
    int mid = (l + r) >> 1;
    update(Left(id), l, mid, pos, val);
    update(Right(id), mid + 1, r, pos, val);
    seg[id] = max(seg[Left(id)], seg[Right(id)]);
}

int get_max(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return -INF;
    if (u <= l && r <= v) return seg[id];

    int mid = (l + r) >> 1;
    return max(get_max(Left(id), l, mid, u, v),
               get_max(Right(id), mid + 1, r, u, v));
}

void process(void) {
    cin >> n >> k;
    FOR(i, 1, n) {
        cin >> a[i];
        zip.add(a[i]);
        zip.add(a[i] - k);
        zip.add(a[i] + k);
        dp[i] = 1;
    }

    zip.init();

    int sz = zip.v.size();

    int ans = -1;

    FOR(i, 1, n) {
        int L = zip.get(a[i] - k);
        int R = zip.get(a[i] + k);
        int Z = zip.get(a[i]);

        int left_max = get_max(1, 1, sz, 1, L);
        int right_max = get_max(1, 1, sz, R, sz);

        dp[i] = max(left_max, right_max) + 1;

//        cout << dp[i] << " ";

        update(1, 1, sz, Z, dp[i]);
        maximize(ans, dp[i]);
    }

    cout << ans;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("E");

//	int t; cin >> t; while(t--)
	process();
	return 0;
}
