/*
	Author: tinhnopro
	created: 04.01.2025 14:15:24
*/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif // LOCAL

#define TASK "number1"

using namespace std;

using i64 = long long;

int solve(int A){
    int ans = 0;
    for(int i = 1; i <= A; i *= 10){
        int temp = i * 10;
        ans += ((A/temp) * i) + min(max(A%temp-i+1, 0), i);
    }
    return ans;
}
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	if (fopen(TASK".inp", "r")) {
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}

	int n; 
	cin >> n; 
	cout << solve(n); 

}