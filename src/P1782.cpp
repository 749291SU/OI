#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int C = 1e4 + 10;
int n, m, c;

LL d[C], g[C];
int q[C];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> c;
	int v, w, s;
	while (n --) {
		cin >> v >> w >> s;
		for (int j = 0; j < v; j ++) {
			int hh = 0, tt = -1;
			for (int k = j; k <= c; k += v) {
				g[k] = d[k];
				if (hh <= tt && q[hh] < k - s * v) hh ++;
				while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w) tt --;
				q[++ tt] = k;
				d[k] = max(d[k], g[q[hh]] + (k - q[hh]) / v * w);
			}
		}	
	}


	int a, b, e;
	while (m --) {
		cin >> a >> b >> e;
		for (int j = c; j >= 0; j --) {
			int t;
			if (a != 0) t = - b / a / 2;
			if (a > 0) {
				if (t <= 0) {
					for (int k = j; k >= 0; k --) {
						LL t = (LL) a * k * k + b * k + e;
						if (t <= 0) break;
						if (d[j - k] + t > d[j]) d[j] = d[j - k] + t;
					}	
				}
				else {
					if (e > 0) d[j] += e;
					for (int k = j; k >= 2 * t; k --) {
						LL t = (LL) a * k * k + b * k + e;
						if (t <= 0) break;
						if (d[j - k] + t > d[j]) d[j] = d[j - k] + t;
					}
				}
			}	
			else if (a == 0) {
				if (b <= 0 && e > 0) d[j] += e;
				else {
					for (int k = j; k >= 0; k --) {
						LL t = (LL) a * k * k + b * k + e;
						if (t <= 0) break;
						if (d[j - k] + t > d[j]) d[j] = d[j - k] + t;
					}
				}
			}
			else {
				if (t <= 0 && e > 0) d[j] += e;
				else {
					for (int k = min(t, j); k >= 0; k --) {
						LL t = (LL) a * k * k + b * k + e;
						if (t <= 0) break;
						if (d[j - k] + t > d[j]) d[j] = d[j - k] + t;
					}
				}
			}
		}
	}			
	cout << d[c] << "\n";

	return 0;
}