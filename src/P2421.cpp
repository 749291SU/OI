#include <iostream>
#include <cstring>
#include <algorithm>

using i64 = long long;

const int N = 110;

int n;
int c[N], p[N], l[N];

inline int extgcd(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	int t = extgcd(b, a % b, y, x);
	y -= a / b * x;
	return t;
}

inline bool check(int m) {
	for (int i = 0; i < n; i ++) {
		for (int j = i + 1; j < n; j ++) {
			int x, y;
			int a = p[i] - p[j], q = c[j] - c[i];	

			int d = extgcd(a, m, x, y), alp1 = m / d;
			if (q % d) continue;
			if (alp1 < 0) alp1 = -alp1;
			x = (x * q / d % alp1 + alp1) % alp1;
			if (x <= l[i] && x <= l[j]) return 0;
		}
	}
	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int ans;
	std::cin >> n;	
	for (int i = 0; i < n; i ++) {
		std::cin >> c[i] >> p[i] >> l[i];
		ans = std::max(ans, c[i]);
	}

	while (!check(ans)) ans ++;
	std::cout << ans << "\n";
	return 0;
}