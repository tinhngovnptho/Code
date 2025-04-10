#include <bits/stdc++.h>

using namespace std;

#define el  "\n"
#define fi  first
#define se  second
#define name "B"
#define BIT(x, i) ((x) & (1 << (i)))
#define MASK(x) (1 << (x))
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(ti, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORDE(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)

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
//const int MOD = 1e9 + 7;
//const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, m;
vi adj[MAXN];
int low[MAXN], num[MAXN];
vector<vi> scc;
int timeDFS  = 0;

void dfs(int u) {
    static stack<int> st;
    low[u] = num[u] = ++timeDFS;
    st.push(u);
    for (int v : adj[u]) {
        if (!num[v]) {
            dfs(v);
            minimize(low[u], low[v]);
        } else minimize(low[u], num[v]);
    }
    if (low[u] == num[u]) {
        int v = 0;
        vi tmp;
        while (v != u) {
            v = st.top();
            tmp.push_back(v);
            low[v] = num[v] = n + 1;
            st.pop();
        }
        scc.push_back(tmp);
    }
}


vector<pair<int, int> > edges; 
int mark[MAXN];

void tinhnop() {
    cin >> n >> m;
		if (n == 0) exit(0);
    FORE(i, 1, m) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
				edges.push_back({u, v});
    }
    FORE(i, 1, n) if (!num[i]) dfs(i);
		
		int res = 1; 

		for (auto &x : scc) {
			for (int v : x) mark[v] = res;
			res++;
		}

		int cnt = 0; 

		for (auto d : edges) {
			if (mark[d.first] == mark[d.second]) cnt++;
		}

		cout << cnt << '\n';

		FORE(i, 1, n) adj[i].clear(); 
		edges.clear(); 
		scc.clear();
		timeDFS = 0; 
		memset(low, 0, sizeof(low));
		memset(num, 0, sizeof(num));
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	#define cherry "b2"
	if (fopen(cherry".inp", "r")) {
		freopen(cherry".inp", "r", stdin);
		freopen(cherry".out", "w", stdout);
	}
 
	while (true) { 
		tinhnop();
	}
 
	cerr <<"\n[runtime] " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.";
	return 0;
}
