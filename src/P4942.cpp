#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL c[20];

LL calc(LL x, int a) {
	LL tmp = x;
	LL p = 0, res = 0;
	while (tmp) {
		int cur = (x % c[p + 1]) / c[p];
		res += (x / c[p + 1]) * c[p];
		if (cur > a) res += c[p];
		else if (cur == a) res += x % c[p] + 1;
		tmp /= 10; p ++;
	}			
	return res;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	c[0] = 1;
	for (int i = 1; i <= 12; i ++) c[i] = c[i - 1] * 10;
	int q; cin >> q;
	while (q --) {
		LL l, r; cin >> l >> r;
		LL res = 0;

		for (int i = 1; i <= 8; i ++) {
			res = (res + i * (calc(r, i) - calc(l - 1, i))) % 9;
		}				
		cout << res << "\n";
	}

	return 0;
}