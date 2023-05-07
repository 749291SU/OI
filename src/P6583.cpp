#include <iostream>
#include <cstring>
#include <algorithm>

using i64 = long long;

i64 n;

inline i64 f(i64 x) {
	i64 res = 0;
	for (i64 i = 1; i <= x; i *= 2) {
		i64 t = x / i;
		for (i64 j = 1; j <= t; j *= 5) {
			res ++;
		}
	}		
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n;

	i64 res = 0;
	for (i64 i = 1, j; i <= n; i = j + 1) {
		i64 x = n / i, ff = f(x); j = n / x;
		i64 t1 = j / 2 - (i - 1) / 2, t2 = j / 5 - (i - 1) / 5, t3 = j / 10 - (i - 1) / 10;
		res += (j - i - t1 - t2 + t3 + 1) * x * ff;
	}
	std::cout << res << "\n";
	return 0;
}