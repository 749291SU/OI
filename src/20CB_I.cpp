#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

const int N = 110;

struct Node {
	int fi, se, th;
	Node() { }
	Node(int fi, int se, int th) : fi(fi), se(se), th(th) { }
} q[N * N * N];

int n, m, k;
int dr[N], dc[N];
int g[N][N], r[N][N];
bool st[N][N][4];
int dist[N][N][4];

int idx[4] = {-1, 0, 1, 0};
int idy[4] = {0, 1, 0, -1};
int off[4] = {-1, 0, 1, -2};

inline double getDist(int x, int y, int _x, int _y) {
	return abs(_x - x) * dr[min(x, _x)] + abs(_y - y) * dc[min(y, _y)];
}

inline int getf(int x, int y, int _x, int _y) {
	return x == _x ? (_y > y ? 1 : 3) : (_x > x ? 2 : 0);
}

inline bool check(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

inline void print_st1(int x, int y, int di, int r1, int _x, int _y, int _di, int r2) {
	cout << x << " " << y << " " << di << " " << r1 << " " << _x << " " << _y << " " << _di << " " << r2 << "\n";
}

inline void print_fenge() {
	cout << "--------------------\n";
}

int solve(int sx, int sy, int ex, int ey, int t, int sdi, int tdi) {
	int hh = 0, tt = -1;
	memset(st, false, sizeof st);	
	memset(dist, 0x3f, sizeof dist);	

	dist[sx][sy][sdi] = t; st[sx][sy][sdi] = true;
	q[++ tt] = Node(sx, sy, sdi);

	while (hh <= tt) {
		Node u = q[hh ++];
		int x = u.fi, y = u.se, di = u.th, distance = dist[x][y][di];	
		st[x][y][di] = false;

		int _x, _y, _di, cost;
		int sig = distance % (g[x][y] + r[x][y]);

		for (int i = 0; i < 4; i ++) {
			_di = (di + off[i] + 4) % 4;
			_x = x + idx[_di], _y = y + idy[_di];
			if (!check(_x, _y)) continue;

			// print_st1(x, y, di, _x, _y, _di);	

			cost = getDist(x, y, _x, _y);

			if (i <= 1) {
				if ((di & 1) && sig < g[x][y]) cost += g[x][y] - sig;
				if (!(di & 1) && sig >= g[x][y]) cost += g[x][y] + r[x][y] - sig;
			}

			if (dist[_x][_y][_di] > distance + cost) {
				// print_st1(x, y, di, distance, _x, _y, _di, distance + cost);	
				dist[_x][_y][_di] = distance + cost;	
				if (!st[_x][_y][_di]) { st[_x][_y][_di] = true; q[++ tt] = Node(_x, _y, _di); }
			}
		}
	}
	return dist[ex][ey][tdi];	
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int preh = 0, h, prew = 0, w;
	for (int i = 1; i < n; i ++) {
		cin >> h;
		dr[i] = h - preh;
		preh = h;
	}	
	for (int i = 1; i < m; i ++) {
		cin >> w;
		dc[i] = w - prew;
		prew = w;
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) cin >> g[i][j];
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) cin >> r[i][j];
	}

	auto print_st = [](int x, int y, int f, int r) {
		cout << x << " " << y << " " << f << " " << r << "\n";
	};

	int hx1, hy1, hx2, hy2;	
	int x1, y1, x2, y2;
	int x3, y3, x4, y4;
	cin >> hx1 >> hy1 >> hx2 >> hy2;
	cin >> k;
	double res = getDist(hx1, hy1, hx2, hy2) / 2;
	int endx = hx2, endy = hy2, endf = getf(hx1, hy1, hx2, hy2);
	// print_st(endx, endy, endf, res);
	while (k --) {
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		int f1 = getf(x1, y1, x2, y2), f2 = getf(x3, y3, x4, y4);

		res = solve(endx, endy, x2, y2, res, endf, f1);
		endx = x2; endy = y2; endf = f1;
		// print_fenge();
		// print_st(endx, endy, endf, res);

		res = solve(endx, endy, x4, y4, res, endf, f2);
		endx = x4; endy = y4; endf = f2;
		// print_fenge();
		// print_st(endx, endy, endf, res);
	}
	res = solve(endx, endy, hx2, hy2, res, endf, getf(hx1, hy1, hx2, hy2));
	res -= getDist(hx1, hy1, hx2, hy2) / 2;
	cout << fixed << setprecision(1) << res << "\n";
	return 0;
}