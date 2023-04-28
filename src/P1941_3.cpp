#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10, M = 1e3 + 10, INF = 0x3f3f3f3f;
int n, m, k;

int x[N], y[N];
int l[N], h[N];
int d[2][M * 2];

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
	for (int i = 0; i <= m; i ++) {
		if (i <= l[0] || i >= h[0]) d[0][i] = INF;
		else d[0][i] = 0;
	}

	for (int i = 1; i <= n; i ++) {
		int _x = x[i - 1], _y = y[i - 1];
		bool flag = false;
		for (int j = 0; j <= m; j ++) d[i % 2][j] = INF;
		for (int j = _x + 1; j <= _x + m; j ++) {
			d[i % 2][j] = min(d[i % 2 ^ 1][j - _x] + 1, d[i % 2][j - _x] + 1);
		}
		for (int j = m + 1; j <= _x + m; j ++) {
			d[i % 2][m] = min(d[i % 2][m], d[i % 2][j]);
		}
		for (int j = 1; j <= m - _y; j ++) {
			d[i % 2][j] = min(d[i % 2][j], d[i % 2 ^ 1][j + _y]);
		}
		for (int j = 0; j <= l[i]; j ++) d[i % 2][j] = INF;
		for (int j = h[i]; j <= m; j ++) d[i % 2][j] = INF;	
		for (int j = 0; j <= m; j ++) {
			if (j <= l[i] || j >= h[i]) d[i % 2][j] = INF;
			if (d[i % 2][j] < INF) flag = true;
		}
		if (flag && h[i] <= m) maxcross ++;
	}

	int ans = INF;
	for (int i = 1; i <= m; i ++) ans = min(ans, d[n % 2][i]);
	if (ans < INF) cout << "1\n" << ans;
	else cout << "0\n" << maxcross;
	cout << "\n";
	return 0;
}