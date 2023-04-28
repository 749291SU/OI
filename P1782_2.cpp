#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int C = 1e4 + 10;
const int N = 1e4 + 10;
int n, m, c;

int d[C], g[C], q[C];

inline int calc(int a, int b, int c, int x) {
	return a * x * x + b * x + c;
}

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
				if (g[q[hh]] + (k - q[hh]) / v * w > d[k]) {
					d[k] = g[q[hh]] + (k - q[hh]) / v * w;
				}
			}
		}	
	}


	int a, b, e;
	while (m --) {
		cin >> a >> b >> e;
		for (int j = c; j >= 0; j --) {
			for (int k = 0; k <= j; k ++) {
				if (d[j - k] + calc(a, b, e, k) > d[j]) {
					d[j] = d[j - k] + calc(a, b, e, k);
				}
			}	
		}
	}			
	cout << d[c] << "\n";

	return 0;
}