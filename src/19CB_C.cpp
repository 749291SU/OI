#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using i64 = long long;

int idx[4] = {-1, 0, 0, 1};
int idy[4] = {0, -1, 1, 0};

int vis[7][7];
bool vis1[7][7];

inline bool check_pos(int x, int y) {
	return x >= 0 && x < 7 && y >= 0 && y < 7;
}

int dfs(int x, int y, int f) {
	int ans = 1;
	vis1[x][y] = true;
	for (int i = 0; i < 4; i ++) {
		int _x = x + idx[i], _y = y + idy[i];	
		if (check_pos(_x, _y) && !vis1[_x][_y] && vis[_x][_y] == f) {
			ans += dfs(_x, _y, f);
		}
	}
	return ans;
}

inline bool check(i64 x) {
	memset(vis, 0, sizeof vis);	
	int cnt = 0;
	int z_x, z_y;
	int x_x, x_y;
	for (int i = 0; i < 49; i ++) {
		if (x & (1ll << i)) {
			vis[i / 7][i % 7] = 1;		
			cnt ++;
			x_x = i / 7; x_y = i % 7;
		}	
		else {
			z_x = i / 7; z_y = i % 7;
		}
	}
	bool f1 = true;
	for (int i = 0; i < 7; i ++) {
		if (!f1) break;
		for (int j = 0; j < 7; j ++) {
			if (vis[i][j] && !vis[6 - j][6 - i]) {
				f1 = false;
				break;
			}	
		}
	}
	bool f2 = true;
	for (int i = 0; i < 7; i ++) {
		if (!f2) break;
		for (int j = 0; j < 7; j ++) {
			if (vis[i][j] && !vis[j][i]) {
				f2 = false;
				break;
			}
		}	
	}	

	if (!f1 && !f2) return false;

	memset(vis1, false, sizeof vis1);
	if (dfs(x_x, x_y, 1) != cnt) return false;
	memset(vis1, false, sizeof vis1);
	if (dfs(z_x, z_y, 0) != 49 - cnt) return false;
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	i64 ans = 0;
	for (i64 i = 0; i < 1ll << 30; i ++) {
		if (check(i)) ans ++;
	}		
	std::cout << ans << "\n";
	return 0;
}