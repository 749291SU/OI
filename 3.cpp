#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> PI;

const int N = 1600;
int n, m;
char a[N][N];
int sx, sy;
int vis[N * N];
int q[N * N];
int idx[4] = {-1, 0, 0, 1};
int idy[4] = {0, -1, 1, 0};
int of_r, of_c;

int fa[N * N];

int fi(int x) {
	return fa[x] == x ? x : fa[x] = fi(fa[x]);
}

inline bool check(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int get_sign(int x, int y) {
	return x * m + y;
}

void pre_deal(int ssx, int ssy) {
	int hh = 0, tt = -1;
	int ss_sign = get_sign(ssx, ssy);
	q[++ tt] = ss_sign;
	vis[ss_sign] = 1;
	while (hh <= tt) {
		int ss = q[hh ++], fss = fi(ss);
		int x = ss / m, y = ss % m;
		for (int i = 0; i < 4; i ++) {
			int _x = x + idx[i], _y = y + idy[i], _ss = get_sign(_x, _y);
			if (!check(_x, _y) || vis[_ss] || a[_x][_y] == '#') continue;
			vis[_ss] = 1; q[++ tt] = _ss;
			fa[fi(_ss)] = fi(fss);
		}
	}
}

bool loop(int s) {
	vis[s] = -1;

	int fs = fi(s);
	// cout << s << "\n";
	for (int i = 0; i < m; i ++) {
		int ss1 = i, ss2 = of_r + i;
		int _ss1 = ss1 + of_r;
		// cout << ss1 << " " << fi(ss1) << " " << s << " " << fs << "\n";
		if (ss1 != s && fi(ss1) == fs) {
			// cout << s << " " << ss1 << "\n";
			if (vis[_ss1] < 0 || (!vis[_ss1] && loop(_ss1))) return true;
			if (ss1 == 0) {
				if (vis[m - 1] < 0 || (!vis[m - 1] && loop(m - 1))) return true;
			}
			if (ss1 = m - 1) {
				if (vis[0] < 0 || (!vis[0] && loop(0))) return true;
			}
		}
		if (ss2 != s && fi(ss2) == fs) {
			// cout << s << " " << ss2 << "\n";
			if (vis[ss1] < 0 || (!vis[ss1] && loop(ss1))) return true;
			if (ss1 == 0) {
				if (vis[n * m - 1] < 0 || (!vis[n * m - 1] && loop(n * m - 1))) return true;
			}
			if (ss1 = m - 1) {
				if (vis[(n - 1) * m] < 0 || (!vis[(n - 1) * m] && loop((n - 1) * m))) return true;
			}
		}
	}		
	// cout << s << "\n";
	for (int i = 0; i < n; i ++) {
		int ss1 = i * m, ss2 = of_c + i * m;
		int _ss1 = ss1 + of_c;
		if (ss1 != s && fi(ss1) == fs) {
			if (vis[_ss1] < 0 || (!vis[_ss1] && loop(_ss1))) return true;
			if (ss1 == 0) {
				if (vis[(n - 1) * m] < 0 || (!vis[m - 1] && loop((n - 1) * m))) return true;
			}
			if (ss1 = (n - 1) * m) {
				if (vis[0] < 0 || (!vis[0] && loop(0))) return true;
			}
		}
		if (ss2 != s && fi(ss2) == fs) {
			if (vis[ss1] < 0 || (!vis[ss1] && loop(ss1))) return true;
			if (ss1 == 0) {
				if (vis[n * m - 1] < 0 || (!vis[n * m - 1] && loop(n * m - 1))) return true;
			}
			if (ss1 = (n - 1) * m) {
				if (vis[m - 1] < 0 || (!vis[m - 1] && loop(m - 1))) return true;
			}
		}
	}
	vis[s] = 1;
	// cout << s << "\n";
	return false;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (cin >> n >> m, n && m) {
		memset(vis, 0, sizeof vis);
		of_r = (n - 1) * m, of_c = m - 1;
		for (int i = 0; i < n * m; i ++) fa[i] = i;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				cin >> a[i][j];
				if (a[i][j] == 'S') {
					sx = i; sy = j;
				}
			}
		}

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if (!vis[get_sign(i, j)] && a[i][j] != '#') pre_deal(i, j);
			}
		}

		// for (int i = 0; i < n; i ++) {
		// 	for (int j = 0; j < m; j ++) {
		// 		if (a[i][j] != '#') {
		// 			cout << i << " " << j << " " << fi(get_sign(i, j)) << "\n";
		// 		}
		// 	}
		// }

		memset(vis, 0, sizeof vis);
		cout << (loop(get_sign(sx, sy)) ? "Yes" : "No") << "\n";
	}
	return 0;
}