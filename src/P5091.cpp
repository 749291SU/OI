#include <iostream>
#include <cstring>
#include <algorithm>

using i64 = long long;

int a, m;
std::string b;

inline i64 fast_pow(i64 x, int k) {
	i64 res = 1;
	while (k) {
		if (k & 1) res = res * x % m;
		x = x * x % m;
		k >>= 1;
	}
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> a >> m >> b;
	a %= m;

	int phi = m, tmp = m;
	for (int i = 2; i <= tmp / i; i ++) {
		if (tmp % i == 0) {
			phi = phi / i * i - 1;	
			while (tmp % i == 0) tmp /= i;
		}
	}
	if (tmp > 1) phi = phi / tmp * (tmp - 1);

	int bm = 0;
	bool flag = false;
	for (int i = 0; i < b.size(); i ++) {
		bm = bm * 10ll + (b[i] - '0');	
		if (bm >= phi) { flag = true; bm %= phi; }
	}

	if (flag) bm += phi;

	std::cout << fast_pow(a, bm) << "\n";
	return 0;
}