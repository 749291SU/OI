#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;
int n;
int g[N][N];


int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) cin >> g[i][j];
	}

	int ans = 0;
	for (int k = n - 1; k > 0; k --) {
		for (int i = 0; i < n; i ++) {
			for (int j = i + 1; j < n; j ++) {
				g[i][j] = g[j][i] = min(g[i][j], g[i][k] + g[k][j]);
				if (i >= k && j >= k) ans += 2 * g[i][j];
			}
		}
	}
	cout << ans << "\n";
	return 0;
}