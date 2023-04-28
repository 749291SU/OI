#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 9901;

typedef long long LL;

int fast_pow(LL x, int k) {
	int res = 1;
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

	int a, b; cin >> a >> b;
	int ans = 1;
	for (int i = 2; i <= a / i; i ++) {
		if (a % i == 0) {
			int tmp = 1;
			while (a % i == 0) { a /= i; tmp = (tmp * i + 1) % MOD; }
			ans = ans * fast_pow(tmp) % MOD;
		}
	}
	if (a > 1) ans = ans * (1 + a) % MOD;
	if (!a) ans = 0;
	cout << ans << "\n";	
	return 0;
}