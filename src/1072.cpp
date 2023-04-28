#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int a0, a1, b0, b1;

int gcd(LL a, LL b) {
	return !b ? a : gcd(b, a % b);
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	while (n --) {
		cin >> a0 >> a1 >> b0 >> b1;
		int t = b1 / b0;

		int ans = 0;
		for (int i = 1; i <= b1 / i; i ++) {
			// if (b1 % i == 0) {
			// 	if (i % t == 0 && gcd(i, a0) == a1 && gcd(i, b0) == i / t) ans ++;	
			// 	if (b1 / i != i) {
			// 		int tmp = b1 / i;
			// 		if (tmp % t == 0 && gcd(tmp, a0) == a1 && gcd(tmp, b0) == tmp / t) ans ++;	
			// 	}
			// }


			if (b1 % i == 0) {
				if (gcd(i, a0) == a1 && gcd(i, b0) == i / t) ans ++;	
				if (b1 / i != i) {
					int tmp = b1 / i;
					if (gcd(tmp, a0) == a1 && gcd(tmp, b0) == tmp / t) ans ++;	
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}