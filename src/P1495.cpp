#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using i64 = long long;

typedef long long LL;

LL extgcd(LL a, LL b, LL& x, LL& y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	LL t = extgcd(b, a % b, y, x);
	y -= a / b * x;
	return t;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

			
	int n; std::cin >> n;
	n --;
	LL a1, m1, a2, m2;		
	std::cin >> a1 >> m1;

	for (int i = 0; i < n; i ++) {
		std::cin >> a2 >> m2;

		LL k1, k2;
		LL d = extgcd(a1, a2, k1, k2), alp1 = a2 / d, gbs = a1 * a2 / d;
		LL t = (m2 - m1) / d;

		k1 = (k1 * t % alp1 + alp1) % alp1;	

		m1 = (k1 * a1 + m1) % gbs;
		a1 = gbs;
	}
	std::cout << m1 << "\n";
	return 0;
}