#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long LL;

LL get(LL x) {
	return x * (x + 1) * (x + 2) / 6;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	LL l, r;
	while (T --) {
		cin >> l >> r;
		l --;
		LL t1 = (sqrt(1 + 8 * l) - 1) / 2, t2 = (sqrt(1 + 8 * r) - 1) / 2;
		LL s1 = (1 + t1) * t1 / 2, s2 = (1 + t2) * t2 / 2;
		LL sum1 = get(t1), sum2 = get(t2);
		l -= s1, r -= s2;
		sum1 += (1 + l) * l / 2, sum2 += (1 + r) * r / 2;
		cout << sum2 - sum1 << "\n";
	}	

	return 0;
}