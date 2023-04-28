#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5002;
int n, r;

int b[N][N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> r;
	int x, y, v;
	int maxx = 0, mayy = 0;
	for (int i = 0; i < n; i ++) {
		cin >> x >> y >> v;
		b[x + 1][y + 1] += v;
		maxx = max(x + 1, maxx);
		mayy = max(y + 1, mayy);
	}		

	int ans = 0;
	for (int i = 1; i <= maxx; i ++) {
		for (int j = 1; j <= mayy; j ++) {
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
			ans = max(ans, b[i][j] - b[i][max(0, j - r)] - b[max(0, i - r)][j] + b[max(0, i - r)][max(0, j - r)]);
		}
	}	
	cout << ans << "\n";
	return 0;
}