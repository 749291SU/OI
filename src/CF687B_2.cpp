#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using i64 = long long;

const int N = 1e6 + 10;
int n, k;
int a[N];

inline bool check(int x, int cnt) {
	for (int j = 0; j < n; j ++) {
		int cnt1 = 0;
		while (a[j] % x == 0) { cnt1 ++; a[j] /= x; }	
		if (cnt1 >= cnt) return true;
	}
	return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n >> k;

	for (int i = 0; i < n; i ++) std::cin >> a[i];

	bool flag = true;
	for (int i = 2; i <= k / i; i ++) {
		int cnt = 0;
		while (k % i == 0) { cnt ++; k /= i; }
		if (cnt > 0) {
			if (!check(i, cnt)) {
				flag = false;
				break;
			}	
		}
	}
	if (k > 1) {
		if (!check(k, 1)) {
			flag = false;
		}
	}

	std::cout << (flag ? "Yes" : "No") << "\n";
	return 0;
}