#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 26;
int n;
bool f[N][N * N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	f[0][0] = f[1][0] = true;
	int ans = n < 2 ? 1 : 0;
	for (int i = 2; i <= n; i ++) {
		for (int j = 0; j <= i * (i - 1) / 2; j ++) {
			bool flag = false;
			for (int k = 0; k <= i - 1; k ++) {
				int t = j - (k + 1) * (i - k - 1);
				if (t >= 0 && f[i - k - 1][j - (k + 1) * (i - k - 1)]) {
					// if (i == n) cout << j << " " << k << " " << t << "\n";
					flag = true;
					break;
				}
			}
			f[i][j] = flag;
			if (i == n && f[i][j]) ans ++;
		}
	}
	cout << ans << "\n";
	return 0;
}