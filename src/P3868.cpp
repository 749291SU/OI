#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int K = 11;
int k;
LL a[K], b[K];

LL gcdext(LL a, LL b, LL& x, LL& y) {
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

	cin >> k;
	for (int i = 0; i < k; i ++) cin >> a[i];
	for (int i = 0; i < k; i ++) cin >> b[i];
	k --;

	LL a1 = b[k], m1 = (a[k] % b[k] + b[k]) % b[k], a2, m2;

	while (k -- > 0) {
		a2 = b[k], m2 = (a[k] % b[k] + b[k]) % b[k];
		LL k1, k2;
		LL d = gcdext(a1, a2, k1, k2), t1 = (m2 - m1) / d, t2 = a2 / d, mod = a1 * t2;

		k1 *= t1; k1 = (k1 % t2 + t2) % t2;

		m1 = (k1 * a1 + m1) % mod;
		a1 *= t2;
	}
	cout << (m1 % a1 + a1) % a1 << "\n";
	return 0;
}