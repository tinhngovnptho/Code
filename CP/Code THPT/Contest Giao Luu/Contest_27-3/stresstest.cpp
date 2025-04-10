#include <bits/stdc++.h>

using namespace std;

#define CHERRY "prefix"

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); 

using i64 = long long; 

i64 randInt(i64 l, i64 r) {
	return uniform_int_distribution<i64> (l, r) (rng); 
}


void gentest() {
	ofstream cout(CHERRY".inp");
	
	int n = randInt(2, 7); 

	cout << n << '\n';
	cout << 0 << ' ' << 0 << ' '; 
	for (int i = 1; i <= n - 2; ++i) {
		cout << randInt(0, i - 1) << ' ';
	}

	cout.close();
}

int main() {
	
	for (int i = 1; i <= 100; ++i) {
		gentest();
		system(CHERRY".exe"); 
		system(CHERRY"_bf.exe"); 

		if (system("fc " CHERRY ".out " CHERRY ".ans") != 0) {
			return 0;
		}
	}
}