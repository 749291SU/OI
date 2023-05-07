#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using i64 = long long;

const int N = 510;
int n;
int a[N * N], nn;
int cnt[N * N];

inline int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

std::unordered_map<int, int> mm;
std::unordered_map<int, int> m2;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n;
	int x, ma = 0;
	for (int i = 0; i < n * n; i ++) {
		std::cin >> x;
		if (!mm[x]) {
			a[nn ++] = x;
		}
		mm[x] ++;
		ma = std::max(ma, x);
	}

	std::sort(a, a + nn);

	for (int i = nn - 1; i >= 0; i --) {
		x = a[i];
		int t1 = m2[x], t2 = 0, cc = mm[x], cnt;
		for (int j = i + 1; j < nn; j ++) {
			if (a[j] % x == 0) t2 += mm[a[j]];
		}	

		cnt = (int) sqrt(t2 * t2 + cc - t1) - t2;
		for (int j = i + 1; j < nn; j ++) {
			int ccc = mm[a[j]];
			if (ccc > 0) {
				int d = gcd(x, a[j]);	
				m2[d] += 2 * cnt * ccc;
			}
		}
		mm[x] = cnt;
		while (cnt --) std::cout << x << "  ";
	}
	std::cout << "\n";
	return 0;
}