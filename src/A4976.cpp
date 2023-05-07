#include <iostream>
#include <cstring>
#include <algorithm>

using i64 = long long;

int n;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int x;
	std::cin >> n;

	int pre = -1;
	bool flag = true;
	for (int i = 0; i < n; i ++) {
		std::cin >> x;
		while (x % 2 == 0) x /= 2;
		while (x % 3 == 0) x /= 3;
		if (pre >= 0 && x != pre) { flag = false; break; }
		pre = x;
	}	
	std::cout << (flag? "Yes" : "No") << "\n"; 
	return 0;
}