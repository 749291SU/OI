#include <iostream>
#include <cstring>
#include <algorithm>

using i64 = long long;

int n;

inline int get(int x) {
	int phi = x;
	for (int j = 2; j <= x / j; j ++) {
		if (x % j == 0) {
			phi = phi / j * (j - 1);
			while (x % j == 0) x /= j;	
		}	
	}
	if (x > 1) phi = phi / x * (x - 1);
	return phi;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n;

	i64 res = 0;
	for (int i = 1; i <= n / i; i ++) {
		if (n % i == 0) {
			res += i * get(n / i);
			if (i != n / i) res += n / i * get(i);
		}	
	}		
	std::cout << res << "\n";
	return 0;
}