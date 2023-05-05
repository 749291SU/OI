#include <iostream>
#include <cstring>
#include <algorithm>

using i64 = long long;

const int N = 1e5 + 10;
int n;
int primes[N], cnt;
bool st[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n;
	n ++;
	std::cout << (n >= 4 ? 2 : 1) << "\n";	
	for (int i = 2; i <= n; i ++) {
		if (!st[i]) { std::cout << 1; primes[cnt ++] = i; }
		else std::cout << 2;
		std::cout << " ";
		for (int j = 0; i <= n / primes[j]; j ++) {
			st[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}
	std::cout << "\n";
	return 0;
}