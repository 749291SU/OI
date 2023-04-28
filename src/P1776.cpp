#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int W = 4e4 + 10, N = 110;
int n, w;

int d[W], g[W], q[W];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> w;
	int v, p, m;
	while (n --) {
		cin >> v >> p >> m;
		memcpy(g, d, sizeof d);
		for (int j = 0; j < p; j ++) {
			int hh = 0, tt = -1;
			for (int k = j; k <= w; k += p) {
				if (hh <= tt && q[hh] < k - m * p) hh ++;
				while (hh <= tt && g[q[tt]] - (q[tt] - j) / p * v <= g[k] - (k - j) / p * v) tt --;
				q[++ tt] = k;
				d[k] = max(d[k], g[q[hh]] + (k - q[hh]) / p * v);
			}
		}
	}
	cout << d[w] << "\n";
	return 0;
}