#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 1e4 + 10;
int t, n, m;
int d[M];
int price[N][N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t >> n >> m;
	for (int i = 0; i < t; i ++) {
		for (int j = 0; j < n; j ++) cin >> price[i][j];
	}
	
	int ans = m;
	for (int i = 0; i < t - 1; i ++) {
		memset(d, ~0x3f, sizeof d);
		d[ans] = ans;
		int ma = 0;
		for (int j = 0; j < n; j ++) {
			for (int k = ans; k >= 0; k --) {
				if (k <= ans - price[i][j]) d[k] = max(d[k], d[k + price[i][j]] + price[i + 1][j] - price[i][j]);
				if (j == n - 1) ma = max(ma, d[k]);
			}
		}
		ans = ma;
	}		
	cout << ans << "\n";
	return 0;
}