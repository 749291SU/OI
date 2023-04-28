#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 51;
int n, m;
char a[N][N];
bool vis[N][N], tmp[N][N], in[N][N];

PII q[N * N];


inline bool check(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int idx[4] = {-1, 0, 0, 1};
int idy[4] = {0, -1, 1, 0};
int idxx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int idyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

inline bool in_loop(int x, int y) {
	int hh = 0, tt = -1;
	q[++ tt] = {x, y};
	tmp[x][y] = true;
	while (hh <= tt) {
		PII t = q[hh ++];
		x = t.first, y = t.second;
		for (int i = 0; i < 8; i ++) {
			int _x = x + idxx[i], _y = y + idyy[i];
			if (!check(_x, _y)) return false;
			if (tmp[_x][_y]) continue;
			tmp[_x][_y] = true;
			q[++ tt] = {_x, _y};
		}
	}

	memcpy(tmp, vis, sizeof vis);
	hh = 0, tt = -1;
	q[++ tt] = {x, y};
	tmp[x][y] = true; in[x][y] = true;
	while (hh <= tt) {
		PII t = q[hh ++];
		x = t.first, y = t.second;
		for (int i = 0; i < 8; i ++) {
			int _x = x + idxx[i], _y = y + idyy[i];
			if (tmp[_x][_y]) continue;
			tmp[_x][_y] = in[x][y] = true;
			q[++ tt] = {_x, _y};
		}
	}
	return true;
}

void solve(int x, int y) {
	int hh = 0, tt = -1;
	vis[x][y] = true;
	q[++ tt] = {x, y};

	while (hh <= tt) {
		PII u = q[hh ++];
		x = u.first, y = u.second;
		for (int i = 0; i < 4; i ++) {
			int _x = x + idx[i], _y = y + idy[i];
			if (!check(_x, _y) || vis[_x][_y] || a[_x][_y] == '0') continue;
			vis[_x][_y] = true;
			q[++ tt] = {_x, _y};
		}
	}
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T --) {
		cin >> n >> m;
		memset(vis, false, sizeof vis);
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) cin >> a[i][j];
		}

		int ans = 0;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if (!vis[i][j] && a[i][j] == '1' && !in[i][j]) {
					memcpy(tmp, vis, sizeof vis);
					in[i][j] = in_loop(i, j);
					if (!in[i][j]) {
						solve(i, j);
						ans ++;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}