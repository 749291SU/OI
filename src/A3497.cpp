#include <iostream>
#include <cstring>
#include <algorithm>

using i64 = long long;

int primes[12000], cnt;
bool st[120001];

inline void sieve(int n) {
	for (int i = 2; i <= n; i ++) {
		if (!st[i]) primes[cnt ++] = i;
		for (int j = 0; i <= n / primes[j]; j ++) {
			st[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	sieve(120000);

	int k;
	while (std::cin >> k) {
		std::cout << primes[k - 1] << "\n";	
	}

	return 0;
}