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
	
	int f;
	LL x, y, m, n, l;	
	cin >> x >> y >> m >> n >> l;
	if ((x > y && m > n) || (x < y && m <= n)) f = -1;	
	else f = 1;

	LL a = abs(m - n), b = l, t, k, c = abs(x - y) * f;	

	LL gc = gcdext(a, b, t, k), gbs = a / gc * b;	
	if (c % gc != 0) { cout << "Impossible\n"; return 0; }
	LL tt = c / gc, alp1 = gbs / a, alp2 = gbs / b;

	LL ans;
	t *= tt; k *= tt;

	LL kk = (k + 1) / alp2;
	while (k - kk * alp2 > -1) kk ++;
	while (t + kk * alp1 < 1) kk ++;
	ans = t + kk * alp1;
	cout << ans << "\n";
	return 0;
}