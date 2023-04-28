#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 110;
int n, w;

int v[N], p[N];
LL d[3 * N][N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> w;
	int minv = 0x3f3f3f3f;
	LL sumv = 0;
	for (int i = 0; i < n; i ++) {
		cin >> v[i] >> p[i];
		minv = min(minv, v[i]);
		sumv += v[i];
	}

	sumv -= n * minv;
	for (int i = 0; i < n; i ++) v[i] -= minv;	

	for (int i = 0; i < n; i ++) {
		for (int j = sumv; j >= 0; j --) {
			for (int k = n; k > 0; k --) {
				if (j >= v[i] && j + (long long) k * minv <= w) {
					d[j][k] = max(d[j][k], d[j - v[i]][k - 1] + p[i]);
				}
			}
		}
	}

	LL ans = 0;
	for (int i = 0; i <= sumv; i ++) {
		for (int j = 0; j < n; j ++) ans = max(ans, d[i][j]);
	}
	cout << ans << "\n";
	return 0;
}