#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int a[32];
LL f[32][1 << 3][2];

LL dp(int x, int st, int isma) {
	if (x == -1) return st == 7 ? 1 : 0;
	LL& ff = f[x][st][isma];
	if (ff >= 0) return ff;

	ff = 0;
	for (int i = 0; i <= 1; i ++) {
		for (int j = 0; j <= 1; j ++) {
			if (isma && (i ^ j) > a[x]) continue;
			if (i == 1 && !(st & 1)) continue;
			if (i && j && !(st & 2)) continue;

			int _st = st;
			if (i == 0 && j == 1) _st |= 1;
			if (i == 1 && j == 0) _st |= 2;
			if (i == 1 && j == 1) _st |= 4;

			ff += dp(x - 1, _st, isma && ((i ^ j) == a[x]));
		}
	}
	return ff;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	LL n;
	while (t --) {
		cin >> n;
		for (int i = 0; i < 32; i ++) {
			a[i] = n & 1ll;
			n >>= 1;
		}
		memset(f, -1, sizeof f);
		cout << dp(31, 0, 1) * 6 << "\n";
	}				
	return 0;
}