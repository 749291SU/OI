#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 666623333;

typedef long long LL;

LL fast_pow(LL x, int k) {
	LL res = 1;
	while (k) {
		if (k & 1) res = res * x % MOD;
		x = x * x % MOD;
		k >>= 1;
	}
	return res;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	LL l, r; cin >> l >> r;
	LL ans = 0;
	for (LL i = l; i <= r; i ++) {
		LL x = i;
		LL tmp = i % MOD;
		for (LL j = 2; j <= x / j; j ++) {
			if (x % j == 0) {
				tmp = tmp * ((j - 1) * fast_pow(j, MOD - 2) % MOD) % MOD;
				while (x % j == 0) x /= j;
			}
		}	
		ans = (ans + ((i - tmp) % MOD + MOD) % MOD) % MOD;
	}
	cout << ans << "\n";
	return 0;
}