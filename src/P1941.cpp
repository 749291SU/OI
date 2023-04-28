#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10, M = 1e3 + 10, INF = 0x3f3f3f3f;
int n, m, k;

int x[N], y[N];
int l[N], h[N];
int d[2][M * 2][2];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	int p;
	l[n] = 0; h[n] = m + 1;
	for (int i = 0; i < n; i ++) { cin >> x[i] >> y[i]; l[i] = 0; h[i] = m + 1; }
	for (int i = 0; i < k; i ++) {
		cin >> p >> l[p] >> h[p];
	}

	int maxcross = h[0] <= m ? 1 : 0;
	for (int i = 1; i <= m; i ++) {
		if (i <= l[0] || i >= h[0]) d[0][i][0] = d[0][i][1] = INF;
		else d[0][i][0] = d[0][i][1] = 0;
	}

	for (int i = 1; i <= n; i ++) {
		int _x = x[i - 1], _y = y[i - 1];
		bool flag = false;
		for (int j = 1; j < m; j ++) {
			d[i % 2][j][0] = INF; d[i % 2][j][1] = INF;

			if (j + _y <= m) d[i % 2][j][1] = min(d[i % 2 ^ 1][j + _y][0], d[i % 2 ^ 1][j + _y][1]);	

			if (j - _x > 0) {
				int t1 = min(d[i % 2 ^ 1][j - _x][0], d[i % 2 ^ 1][j - _x][1]);
				d[i % 2][j][0] = min(t1, d[i % 2][j - _x][0]) + 1;		
			}
		}
		d[i % 2][m][0] = d[i % 2][m][1] = INF;
		for (int j = 1; j < m; j ++) {
			d[i % 2][m][0] = min(d[i % 2][m][0], min(d[i % 2 ^ 1][j][0], d[i % 2 ^ 1][j][1]) + (m - j - 1) / _x + 1);
		}
		d[i % 2][m][0] = min(d[i % 2][m][0], min(d[i % 2 ^ 1][m][0], d[i % 2 ^ 1][m][1]) + 1);

		for (int j = 0; j <= m; j ++) {
			if (j <= l[i] || j >= h[i]) d[i % 2][j][0] = d[i % 2][j][1] = INF;
			if (min(d[i % 2][j][0], d[i % 2][j][1]) < INF) flag = true;
		}
		if (flag && h[i] <= m) maxcross ++;
	}

	int ans = INF;
	for (int i = 1; i <= m; i ++) ans = min(ans, min(d[n % 2][i][0], d[n % 2][i][1]));
	if (ans < INF) cout << "1\n" << ans;
	else cout << "0\n" << maxcross;
	cout << "\n";
	return 0;
}