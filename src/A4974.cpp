#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int n; std::cin >> n;
	std::vector<int> a(n), b(n), c(n);

	for (int i = 0; i < n; i ++) std::cin >> a[i];

	int ans = 0;
	int i = 0, j;	
	int hh1 = 0, tt1 = -1;
	int hh2 = 0, tt2 = -1;
	for (j = 0; j < n; j ++) {
		while (hh1 <= tt1 && a[j] < a[b[tt1]]) tt1 --;	
		while (hh2 <= tt2 && a[j] > a[c[tt2]]) tt2 --;
		b[++ tt1] = j; c[++ tt2] = j;

		int t = a[b[hh1]] - a[c[hh2]];
		if (std::abs(t) <= 1) continue;

		ans = std::max(ans, j - i);
		if (a[j] == a[b[hh1]]) {
			while (hh2 <= tt2 && a[c[hh2]] - a[j] > 1) hh2 ++;	
			i = c[hh2];	
		}
		else {
			while (hh1 <= tt1 && a[j] - a[b[hh1]] > 1) hh1 ++;
			i = b[hh1];
		}
	}	
	ans = std::max(ans, j - i);
	std::cout << ans << "\n";
	return 0;
}