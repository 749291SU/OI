#include <iostream>
#include <cstring>
#include <algorithm>

using i64 = long long;

i64 n, k;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n >> k;
	i64 ans = n > k ? k * k + (n - k) * k : n * k;
	n = std::min(n, k);
	for (i64 l = 1, r; l <= n; l = r + 1) {
		r = std::min(n, k / (k / l));
		ans -= (k / l) * (r - l + 1) * (r + l) / 2;
	}
	std::cout << ans << "\n";
	return 0;
}