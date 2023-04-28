#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e3 + 10;
int n, m, k;

int fac[N], fac_inv[N];
int fact[N][N];
int cnt[N][N];

int fast_pow(int x) {
	int res = 1;
	int t = k - 2;
	while (t) {
		if (t & 1) res = res * x % k;
		x = x * x % k;
		t >>= 1;
	}
	return res;
}

int C(int i, int j) {
	return fac[i] * fac_inv[j] * fac_inv[i - j] % k;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T >> k;
/*	fac[0] = 1, fac_inv[0] = 1;
	for (int i = 1; i <= N; i ++) {
		fac[i] = fac[i - 1] * i % k;
		fac_inv[i] = fast_pow(fac[i]);
	}*/

	fact[0][0] = 1;
	for (int i = 1; i < N; i ++) {
		fact[i][0] = 1;
		for (int j = 1; j <= i; j ++) {
			fact[i][j] = (fact[i - 1][j] + fact[i - 1][j - 1]) % k;
			cnt[i][j] = cnt[i][j - 1] + cnt[i - 1][j] - cnt[i - 1][j - 1];
			if (fact[i][j] == 0) cnt[i][j] ++;
		}
		for (int j = i + 1; j < N; j ++) {
			cnt[i][j] = cnt[i][j - 1] + cnt[i - 1][j] - cnt[i - 1][j - 1];
		}
	}

	while (T --) {
		int ans = 0;
		cin >> n >> m;
		// for (int i = 0; i <= n; i ++) {
		// 	for (int j = 0; j <= m; j ++) cout << cnt[i][j] << " ";
		// 	cout << "\n";
		// }
		// for (int i = 0; i <= n; i ++) {
		// 	for (int j = 0; j <= min(i, m); j ++) {
		// 		if (fact[i][j] % k == 0) {
		// 			// cout << i << " " << j << "\n";
		// 			ans ++;
		// 		}
		// 	}
		// }
		cout << cnt[n][m] << "\n";

		// cout << ans << "\n";
	}
	return 0;
}