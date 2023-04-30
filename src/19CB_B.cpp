#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using i64 = long long;

std::vector<int> primes;	
std::vector<bool> st(2020, false);
i64 ans;

// std::vector<std::vector<i64>> d(2020, std::vector<i64>(1000, -1));
// i64 dfs(int start, int t) {
// 	i64& dd = d[t][start];
// 	if (dd >= 0) return dd;
// 	if (t == 0) return dd = 1;
// 	dd = 0;
// 	for (int i = start; i < primes.size() && primes[i] <= t; i ++) {
// 		dd += dfs(i + 1, t - primes[i]);
// 	}	
// 	return dd;
// }

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);


	for (int i = 2; i <= 2019; i ++) {
		if (!st[i]) primes.push_back(i);
		for (int j = 0; i <= 2019 / primes[j]; j ++) {
			st[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}

	// ans = dfs(0, 2019);

	std::vector<std::vector<i64>> d(2020, std::vector<i64>(1000));
	for (int i = 1; i <= 2019; i ++) {
		for (int j = 0; j < primes.size() && primes[j] <= i; j ++) {
			int pri = primes[j], t =  i - pri;
			for (int k = 0; k < primes.size() && primes[k] <= t && primes[k] < pri; k ++) {
				d[i][j] += d[t][k];	
			}
			if (t == 0) d[i][j] += 1;
			if (i == 2019) {
				ans += d[i][j];
			}
		}				
	}	
	std::cout << ans << "\n";
	return 0;
}