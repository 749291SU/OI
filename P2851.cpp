#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int T = 1200001, N = 110, INF = 0x3f3f3f3f;
int t, n;

int a[N], b[N];
int d[T], g[T], q[T];
int f[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> t;
	f[n] = t;
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 0; i < n; i ++) { cin >> b[i]; f[i] = max(t, a[i] * b[i]); }

	d[0] = 0;
	for (int i = 1; i <= f[0]; i ++) d[i] = INF;
	for (int i = 0; i < n; i ++) {
		int v = a[i], s = b[i];
		for (int j = 0; j < v; j ++) {
			int hh = 0, tt = -1;
			for (int p = s; p > 0; p --) {
				int _t = abs(j - p * v);
				while (hh <= tt && g[abs(q[tt])] + (abs(q[tt] - j)) / v >= g[_t] + (_t - j) / v) tt --;
				q[++ tt] = -_t;
				g[_t] = d[_t];
			}	
			for (int k = j; k <= f[i + 1]; k += v) {
				g[k] = d[k];
				if (hh <= tt && q[hh] < k - s * v) hh ++;
				while (hh <= tt && g[abs(q[tt])] + (k - q[hh]) / v >= g[k]) tt --;		
				q[++ tt] = k;
				d[k] = min(d[k], g[abs(q[hh])] + (k - q[hh]) / v);
			}	
		}	
	}
	cout << (d[t] == INF ? -1 : d[t]) << "\n";
	return 0;
}