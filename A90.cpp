#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	LL a, b, p;
	cin >> a >> b >> p;

	LL t1 = a * b, t2 = (LL) ((long double) a * b / p) * p;
	LL ans = ((t1 - t2) % p + p) % p;
	cout << ans << "\n";
	return 0;
}