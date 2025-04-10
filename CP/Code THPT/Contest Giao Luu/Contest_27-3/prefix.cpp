// tinhnopro 
#include <bits/stdc++.h>
using namespace std; 

#define hanh "prefix"

using i64 = long long;

const int maxN = 1e5 + 5; 

int n, f[maxN], pi[maxN];
char s[maxN]; 

void Input() {
	cin >> n; 
	for (int i = 1; i <= n; ++i) {
		cin >> f[i];
	}
}

void Main() {
	s[1] = 'a'; 
	pi[1] = 0;

	bool ok = true; 
	for (int i = 2; i <= n; ++i) {
		if (f[i] > 0) {
			s[i] = s[f[i]];

			int j = pi[i - 1]; 

			while (j > 0 && s[j + 1] != s[i]) j = pi[j]; 

			if (j < i && s[j + 1] == s[i]) pi[i] = j + 1;
			else pi[i] = 0; 

			if (f[i] != pi[i]) {
				ok = false; 
				break;
			}
		} else {
			bool found = false; 

			for (char c = 'a'; c <= 'z'; ++c) {
				s[i] = c; 

				int j = pi[i - 1]; 

				while (j > 0 && s[j + 1] != s[i]) j = pi[j]; 
	
				if (j < i && s[j + 1] == s[i]) pi[i] = j + 1;
				else pi[i] = 0; 
	
				if (f[i] == pi[i]) {
					found = true; 
					break;
				}
			}

			if (!found) {
				ok = false; 
				break; 
			}
		}
	}

	if (!ok) cout << -1; 
	else {
		for (int i = 1; i <= n; ++i) cout << s[i]; 
	}
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); 
	
	if (fopen(hanh".inp", "r")) {
		freopen(hanh".inp", "r", stdin); 
		freopen(hanh".out", "w", stdout);
	}

	int t = 1; 
	// cin >> t; 
	for (int i = 1; i <= t; ++i) {
		Input();
		Main();
	}

	cerr << "\n[runtime]" << 1.0 * clock() / CLOCKS_PER_SEC << "[ms]";
	return 0; 
}