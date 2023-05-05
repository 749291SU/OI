#include <iostream>
#include <cstring>
#include <algorithm>

using i64 = long long;

int n;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n;

	i64 res = n;

	for (int i = 2; i <= n / i; i ++) {
		int cnt = 0;
		while (n % i == 0) {
			n /= i;
			cnt ++;
		}
		if (cnt > 0) {
			res /= i;
			res *= cnt * i - cnt + i;
		}
	}
	if (n > 1) { res /= n; res *= 2 * n - 1; }
	std::cout << res << "\n";
	return 0;
}