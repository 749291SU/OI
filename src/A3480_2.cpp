#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using i64 = long long;

int g[6][6];

int idx[4] = {-1, 0, 0, 1};
int idy[4] = {0, -1, 1, 0};
int sx, sy, ex, ey;

inline bool check(int x, int y) {
	return x >= 0 && x < 6 && y >= 0 && y < 6;
}

int ans = 400;
bool vis[6][6];
void dfs(int x, int y, int st, int cost) {
	if (cost + std::abs(ex - x) + std::abs(ey - y) >= ans) return ;
	if (x == ex && y == ey) { ans = min(ans, cost); return ; }
	for (int i = 0; i < 4; i ++) {
		int _x = x + idx[i], _y = y + idy[i];
		if (!check(_x, _y) || vis[_x][_y]) continue;
		vis[_x][_y] = true;
		if (dfs(_x, _y, g[_x][_y] * st % 4 + 1, cost + g[_x][_y] * st)) return true;
		vis[_x][_y] = false;
	}	
	return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	
	for (int i = 0; i < 6; i ++) {
		for (int j = 0; j < 6; j ++) {
			std::cin >> g[i][j];
		}
	}
	std::cin >> sx >> sy >> ex >> ey;

	dfs(sx, sy, 0, 0);

	std::cout << ans << "\n";
	
	return 0;
}