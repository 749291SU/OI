#include <iostream>
#include <cstring>
#include <algorithm>

using i64 = long long;

const int MOD = 19260817;

i64 fast_pow(i64 x, int k) {
	i64 res = 1;
	while (k) {
		if (k & 1) res = res * x % MOD;
		x = x * x % MOD;
		k >>= 1;
	}
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::string a, b, c;
	std::cin >> a >> b;

	int x = 0;
	for (int i = 0; i < b.size(); i ++) {
		x = x * 10 + b[i] - '0';
		if (x >= MOD) x %= MOD;
	}				
	if (x == 0) { std::cout << "Angry\n"; return 0; }

	int ans = 0, xx = fast_pow(x, MOD - 2);
	
	int t = 0;
	for (int i = a.size() - 1; i >= 0; i --) {
		t += (a[i] - '0') * xx;
		c.push_back(t % 10 + '0');
		t /= 10;
	}
	while (t) {
		c.push_back(t % 10 + '0');
		t /= 10;
	}

	for (int i = c.size() - 1; i >= 0; i --) {
		ans = ans * 10 + c[i] - '0';	
		if (ans >= MOD) ans %= MOD;
	}
	std::cout << ans << "\n";
	return 0;
}