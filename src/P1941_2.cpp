#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10, M = 1e3 + 10, INF = 0x3f3f3f3f;
int n, m, k;

int x[N], y[N];
int l[N], h[N];
int d[M], g[M];

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
		d[0][i] = (i <= l[0] || i >= h[0]) ? INF : 0;
	}

	for (int i = 1; i <= n; i ++) {
		int _x = x[i - 1], _y = y[i - 1];
		memcpy(g, d, sizeof d);
		bool flag = false;
		for (int j = 1; j < m; j ++) {
			d[j] = INF;
			if (j <= l[i] || j >= h[i]) continue ;

			if (j + _y <= m) d[j] = min(d[j], g[j + _y]);	
			for (int k = j - _x; k > 0; k -= _x) {
				d[j] = min(d[j], g[k] + (j - k) / _x);
			}
			if (d[j] < INF) flag = true;
		}
		d[m] = INF;
		if (m > l[i] && m < h[i]) {
			for (int j = 1; j <= m; j ++) {
				d[m] = min(d[m], g[j] + (m - j - 1) / _x + 1);
			}	
			if (d[m] < INF) flag = true;
		}
		if (flag && h[i] <= m) maxcross ++;
	}

	int ans = INF;
	for (int i = 1; i <= m; i ++) ans = min(ans, d[i]);
	if (ans < INF) cout << "1\n" << ans;
	else cout << "0\n" << maxcross;
	cout << "\n";
	return 0;
}