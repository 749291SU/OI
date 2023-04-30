#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using i64 = long long;

i64 ans;

int idx[4] = {-1, 0, 0, 1};
int idy[4] = {0, -1, 1, 0};
bool vis[6][6];

inline bool check(int x ,int y) {
	return x >= 0 && x < 6 && y >= 0 && y < 6;
}

void dfs(int x, int y, int h) {
	if (x == 0 && y == 0 && h == 0) { ans ++; return ;}
	if (h == 0) return ;

	for (int i = 0; i < 4; i ++) {
		int _x = x + idx[i], _y = y + idy[i];
		if (check(_x, _y) && !vis[_x][_y]) { 
			vis[_x][_y] = true;
			dfs(_x, _y, h - 1);
			vis[_x][_y] = false;
		}
	}	
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	for (int i = 3; i <= 12; i ++) {
		memset(vis, false, sizeof vis);
		dfs(0, 0, i);	
	}
	std::cout << ans << "\n";
	return 0;
}