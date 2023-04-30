#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int ans;
	for (ans = 4039; ; ans ++) {
		double t = std::sqrt(2 * ans * ans + 2019 * 2019);
		if (std::fabs(t - (int) t) < 1e-18) {
			int x = (int) t - ans, y = ans - x;
			if (ans - x > 2019 && ans != 2 * x) {
				std::cout << x << " " << ans - x << "\n";
				break;
			}
		}
	}
	return 0;
}