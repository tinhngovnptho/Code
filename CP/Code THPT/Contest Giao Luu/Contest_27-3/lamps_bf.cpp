#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ull unsigned long long
#define ii pair <int , int>
#define iii pair <int , ii>
#define fi first
#define se second
#define pb push_back
#define el '\n'
#define file(name)  if (fopen (name".inp", "r") ) { freopen (name".inp", "r", stdin); freopen (name".out", "w", stdout); }
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TuanM signed main

const int MOD = 1e9 + 7;
const int oo = 1e18;

int t;
int n , m;
int f[50005];
int res;

int a[500][500];

void debug(){
    int tmp = 0;
    memset(a , 0 , sizeof a);

    for(int k = 1 ; k <= n ; k ++){
        for(int i = 1 ; i <= n ; i ++){
            if (i % k == 0){
                for(int j = 1 ; j <= m ; j ++){
                    if (a[i][j] == 0) a[i][j] = 1;
                    else a[i][j] = 0;
                }
            }
        }

//        for(int i = 1 ; i <= n ; i ++){
//            for(int j = 1 ; j <= m ; j ++){
//                cout << a[i][j] << " ";
//            }
//            cout << el;
//        }
//
//        cout << el;
    }

    for(int k = 1 ; k <= m ; k ++){
        for(int j = 1 ; j <= m ; j ++){
            if (j % k == 0){
                for(int i = 1 ; i <= n ; i ++){
                    if (a[i][j] == 0) a[i][j] = 1;
                    else a[i][j] = 0;
                }
            }
        }

    }

		for(int i = 1 ; i <= n ; i ++){
			for(int j = 1 ; j <= m ; j ++){
					cout << a[i][j] << " ";
			}
			cout << el;
		}

		cout << el;

    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= m ; j ++){
            if (a[i][j] == 1) tmp ++;
        }
    }

    cout << tmp << el;

}

void solve(){
    cin >> n >> m;

    debug();
}

TuanM(){
    fastio

    // freopen("lamps.inp","r",stdin);
    // freopen("lamps.ans","w",stdout);

    cin >> t;

    while(t --){
        solve();
    }

    return 0;
}