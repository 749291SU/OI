#include <iostream>
#include <cstring>
#include <algorithm>

using i64 = long long;

const int MOD = 19260817;

inline int extgcd(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	int t = extgcd(b, a % b, y, x);
	y -= a / b * x;
	return t;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::string a, b, c;
	std::cin >> a >> b;

	int bb = 0;
	for (int i = 0; i < b.size(); i ++) {
		bb = bb * 10 + b[i] - '0';
		if (bb >= MOD) bb %= MOD;
	}				
	if (bb == 0) { std::cout << "Angry\n"; return 0; }

	bool nega = false;
	int x, y;
	extgcd(bb, MOD, x, y);
	
	if (x < 0) { x = -x; nega= true; }

	int t = 0, ans = 0;	
	for (int i = a.size() - 1; i >= 0; i --) {
		t += (a[i] - '0') * x;
		c.push_back(t % 10 + '0');
		t /= 10;
	}	
	while (t) {
		c.push_back(t % 10 + '0');
		t /= 10;
	}
	for (int i = c.size() - 1; i >= 0; i --) {
		ans = ans * 10 + c[i] - '0';
		if (ans >= MOD) ans %= MOD;
	}
	if (nega) ans = MOD - ans;
	std::cout << ans << "\n";
	return 0;
}