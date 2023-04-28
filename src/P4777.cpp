#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

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

	int n; cin >> n;

	LL a1, m1, a2, m2;
	cin >> a1 >> m1;

	while (n -- > 1) {
		cin >> a2 >> m2;
		LL k1, k2;
		LL d = gcdext(a1, a2, k1, k2), t1 = (m2 - m1) / d, t2 = a2 / d;
		LL mod = a1 * t2;

		k1 = ((k1 % t2 + t2) % t2) * ((t1 % t2 + t2) % t2) % t2;

		m1 = ((k1 % mod) * (a1 % mod) + m1) % mod;
		a1 = mod;
	}
	cout << m1 % a1 << "\n";
	return 0;
}