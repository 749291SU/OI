#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int idx[4] = {-1, 0, 0, 1};
int idy[4] = {0, -1, 1, 0};

bool vis[4][4];
long long ans;

inline bool check(int x, int y) {
	return x >= 0 && x < 4 && y >= 0 && y < 4;
}
void dfs(int x, int y, int cnt) {
	vis[x][y] = true;
	
	if (cnt == 16) ans ++;

	for (int i = 0; i < 4; i ++) {
		int _x = x + idx[i], _y = y + idy[i];
		if (check(_x, _y) && !vis[_x][_y]) {
			dfs(_x, _y, cnt + 1);
		}
	}
	vis[x][y] = false;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 4; i ++) {
		for (int j = 0; j < 4; j ++) dfs(i, j, 1);
	}
	cout << ans << "\n"; 
	return 0;
}