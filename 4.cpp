#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1510;
int n, m;

char a[N][N];
int vis[N][N][3];
int sx, sy;

int idx[4] = {-1, 0, 0, 1};
int idy[4] = {0, -1, 1, 0};
bool dfs(int x, int y, int lx, int ly) {
	if (vis[x][y][0] && (vis[x][y][1] != lx || vis[x][y][2] != ly)) {
		return true;
	}
	vis[x][y][0] = 1;
	vis[x][y][1] = lx; vis[x][y][2] = ly;

	for (int i = 0; i < 4; i ++) {
		int _x = (x + idx[i] + n) % n, _y = (y + idy[i] + m) % m;
		int _lx = lx + idx[i], _ly = ly + idy[i];
		if (a[_x][_y] != '#' && (!vis[_x][_y][0] || vis[_x][_y][1] != _lx || vis[_x][_y][2] != _ly)) {
			if (dfs(_x, _y, _lx, _ly)) return true;
		}
	}
	return false;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (cin >> n >> m) {
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				cin >> a[i][j];
				if (a[i][j] == 'S') {
					sx = i; sy = j;
				}
			}
		}
		cout << (dfs(sx, sy, sx, sy) ? "Yes" : "No") << "\n";
	}
	return 0;
}