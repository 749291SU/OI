#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using i64 = long long;

bool calc(i64 x) {
	int ans = 1;
	for (i64 i = 2; i <= x / i; i ++) {
		int cnt = 0;
		while (x % i == 0) { cnt ++; x /= i; }	
		ans *= cnt + 1;
		if (ans > 100) return false;
	}	
	if (x > 1) ans *= 2;
	return ans == 100;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	for (i64 i = 1; ; i ++) {
		if (calc(i)) {
			std::cout << i << "\n";
			break;
		}	
	}	
	return 0;
}