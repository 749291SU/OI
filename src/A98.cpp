#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;

PII calc(int n, LL A) {
	if (n == 0) return {0, 0};		
	LL cnt = 1ll << (2 * n - 2), len = 1ll << (n - 1), pos = A / cnt;
	PII t = calc(n - 1, A % cnt);
	LL x = t.first, y = t.second;

	if (pos == 0) return {y, x};
	if (pos == 1) return {x, y + len};
	if (pos == 2) return {x + len, y + len};
	if (pos == 3) return {2 * len - y - 1, len - x - 1};
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int N;
	LL A, B;
	while (n --) {
		LL ans;
		cin >> N >> A >> B;
		PII t1 = calc(N, A - 1), t2 = calc(N, B - 1);
		double tt1 = fabs(t2.first - t1.first), tt2 = fabs(t2.second - t1.second);
		if (tt1 < 1e-8) ans = (LL) (tt2 * 10 + 0.5);
		else if (tt2 < 1e-8) ans = (LL) (tt1 * 10 + 0.5);
		else ans = (LL) (tt2 * 10 / sin(atan(tt2 / tt1)) + 0.5);
		cout << ans << "\n";
	}	
	return 0;
}