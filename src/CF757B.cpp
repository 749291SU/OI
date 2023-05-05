#include <iostream>
#include <cstring>
#include <algorithm>

using i64 = long long;

const int N = 1e5 + 10;
int n;
int cnt[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n;
	int x;
	int ma = 0;
	for (int i = 0; i < n; i ++) {
		std::cin >> x;
		ma = std::max(ma, x);
		for (int j = 2; j <= x / j; j ++) {
			if (x % j == 0) {
				cnt[j] ++;
				while (x % j == 0) x /= j;
			}		
		}
		if (x > 1) cnt[x] ++;
	}

	int ans = 1;
	for (int i = 0; i <= ma; i ++) {
		ans = std::max(ans, cnt[i]);
	}
	std::cout << ans << "\n";
	return 0;
}