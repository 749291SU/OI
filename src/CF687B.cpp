#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using i64 = long long;

const int N = 1e6 + 10;
int cn1[N], cn2[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int n, k, tmp;
	std::cin >> n >> k; tmp = k;

	for (int i = 2; i <= tmp / i; i ++) {
		int cnt = 0;
		while (tmp % i == 0) { cnt ++; tmp /= i; }
		cn1[i] = std::max(cn1[i], cnt);
	}
	if (tmp > 1) cn1[tmp] = std::max(cn1[tmp], 1);

	bool flag = true;
	int x;
	for (int i = 0; i < n; i ++) {
		std::cin >> x;
		if (!flag) break;
		for (int j = 2; j <= x / j; j ++) {
			int cnt = 0;
			while (x % j == 0) { cnt ++; x /= j; }	
			cn2[j] = std::max(cn2[j], cnt);
		}
		if (x > 1) {
			cn2[x] = std::max(cn2[x], 1);
		}
	}

	for (int i = 2; i <= k; i ++) {
		if (cn1[i] > cn2[i]) {
			flag = false;
			break;
		}	
	}
	std::cout << (flag ? "Yes" : "No") << "\n";
	return 0;
}