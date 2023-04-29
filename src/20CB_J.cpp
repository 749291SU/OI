#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

#pragma GCC optimize(2)	

typedef long long LL;

const int N = 1e3 + 10, MOD = 1e9 + 7;
const LL t1 = 1e4, t2 = 1e8;

int n, m, w;
int r1, c1, h1, r2, c2, h2;
LL xi1, xi2;

int primes[1000], cnt;
bool st[1000];

inline void get(int n) {
	for (int i = 2; i <= n; i ++) {
		if (!st[i]) primes[cnt ++] = i;
		for (int j = 0; i <= n / primes[j]; j ++) {
			st[i * primes[j]] = true;
			if (i % primes[j] == 0) break;	
		}
	}
}

inline LL pack(LL x, LL y, LL h) {
	return x * t2 + y * t1 + h;	
}

unordered_map<LL, LL> mm;
LL dp(LL x) {
	if (mm.count(x)) return mm[x];
	LL& ff = mm[x];
	if (x == xi1 || x == xi2) return ff = 0;
	LL _x = x / t2, _y = (x % t2) / t1, _h = x % t1;
	if (_x == 1 && _y == 1 && _h == 1) return ff = 1;

	for (int i = 0; i < cnt; i ++) {
		int pri = primes[i];
		if (pri >= _x) break;
		ff = (ff + dp(pack(_x - pri, _y, _h))) % MOD;
	}

	for (int i = 0; i < cnt; i ++) {
		int pri = primes[i];
		if (pri >= _y) break;
		ff = (ff + dp(pack(_x, _y - pri, _h))) % MOD;
	}

	for (int i = 0; i < cnt; i ++) {
		int pri = primes[i];
		if (pri >= _h) break;
		ff = (ff + dp(pack(_x, _y, _h - pri))) % MOD;
	}

	return ff;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> w;
	cin >> r1 >> c1 >> h1 >> r2 >> c2 >> h2;		
	xi1 = pack(r1, c1, h1); xi2 = pack(r2, c2, h2);

	get(1000);	

	cout << dp(pack(n, m, w)) << "\n";

	return 0;
}