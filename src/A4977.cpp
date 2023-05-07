#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using i64 = long long;

const int N = 2e5 + 10;
int n, k;

std::unordered_map<int, i64> mm1, mm2;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n >> k;

	int x;
	i64 ans = 0;
	for (int i = 0; i < n; i ++) {
		std::cin >> x;
		if (x % k == 0) {
			ans += mm1[x / k];
			mm1[x] += mm2[x / k];
		}
		mm2[x] ++;
	}
	std::cout << ans << "\n";
	return 0;
}