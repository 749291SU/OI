#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e3 + 10;
int n, m, k;

int fac[N], fac_inv[N];

int C(int i, int j) {
	return fac[i] * fac_inv[j] * fac_inv[i - j] % k;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T >> k;
	fac[0] = 1, fac_inv[0] = 1;
	for (int i = 1; i <= N; i ++) {
		fac[i] = fac[i - 1] * i % k;

	}

	while (T --) {
		int ans = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= min(i, m); j ++) {
				if (C(i, j) == 0) ans ++;
			}
		}	
		cout << ans << "\n";
	}
	return 0;
}