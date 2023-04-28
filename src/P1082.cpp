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

	LL a, b; cin >> a >> b;
	LL x, y;

	LL gc = gcdext(a, b, x , y), gbs = a / gc * b;
	// cout << x << " " << gbs / a << "\n";
	while (x > 0) x -= gbs / a;
	while (x <= 0) x += gbs / a;
	cout << x << "\n";
	return 0;
}