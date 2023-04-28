#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int n, p;

// inline int fast_pow(LL x, int k) {
// 	int res = 1;	
// 	while (k) {
// 		if (k & 1) res = res * x % p;
// 		x = x * x % p;
// 		k >>= 1;
// 	}
// 	return res;
// }

inline LL gcdext(LL a, LL b, int& x, int& y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}	
	LL t = gcdext(b, a % b, y, x);
	y -= a / b * x;
	return t;
}


int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cin >> n >> p;
	for (LL i = 1; i <= n; i ++) {
		int x, y;
		LL t = gcdext(i, p, x, y), gbs = i / t * p;
		while (x <= 0) x += gbs / i;
		cout << x << "\n";
	}
	return 0;
}