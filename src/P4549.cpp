#include <iostream>
#include <cstring>
#include <algorithm>

using i64 = long long;

int n;

inline int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n;
	int res = 0, x;
	for (int i = 0; i < n; i ++) {
		std::cin >> x;
		res = !res ? x : gcd(res, std::abs(x));	
	}	
	std::cout << res << "\n";	

	return 0;
}