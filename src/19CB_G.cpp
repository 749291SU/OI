#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using i64 = long long;

const int MOD = 123456;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int n, k; std::cin >> n >> k;
	std::vector<int> d(k + 1);

	d[1] = 2;
	for (int i = 3; i <= n; i ++) {
		for (int j = std::min(k, i); j >= 1; j --) {
			d[j] = (d[j] * j + d[j - 1] * 2) % MOD;	
			if (j >= 2) d[j] = (d[j] + d[j - 2] * (i - j)) % MOD; 
		}	
	}
	if (n == 1) std::cout << 1;
	std::cout << d[k] << "\n";
	return 0;
}