#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int n; std::cin >> n;
	std::vector<int> a(n);

	for (int i = 0; i < n; i ++) std::cin >> a[i];

	int f = 0, pre = -1;
	int ans = 0;
	int i = 0, j;
	for (j = 0; j < n; j ++) {
		if ((a[j] > a[j - 1] && f > 0) || (a[j] < a[j - 1] && f < 0)) {
			ans = std::max(ans, j - i);
			i = pre;
		}	
		
		if (pre != -1 && j && a[j] != a[j - 1]) f = a[j] > a[pre] ? 1 : a[j] < a[pre] ? -1 : 0;
		if (pre == -1 || (j && a[j] != a[j - 1])) pre = j;
	}
	ans = std::max(ans, j - i);
	std::cout << ans << "\n";
	return 0;
}