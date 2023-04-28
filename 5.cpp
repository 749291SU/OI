#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 27, M = 610;
int n, m;

int d[N], tmp[N];
int q[N];
int g[N][N];

int solve() {
	int hh = 0, tt = -1;
	memcpy(tmp, d, sizeof d);
	bool multi = false;	
	for (int i = 0; i < n; i ++) {
		if (tmp[i] == 0) { 
			q[++ tt] = i;
			if (tt > 0) multi = true;
		}
	}	

	while (hh <= tt) {
		int u = q[hh ++];
		for (int i = 0; i < n; i ++) {
			if (g[u][i] && (-- tmp[i] == 0)) q[++ tt] = i;
		}
	}
	if (tt != n - 1) return -1;
	if (multi) return 0;
	return 1;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	char c;
	int a, b;
	int ans, target = -1, cnt = 0;
	while (m --) {
		cnt ++;
		cin >> c; a = c - 'A';
		cin >> c;
		cin >> c; b = c - 'A';
		if (!g[a][b]) d[b] ++;
		g[a][b] = 1;
		ans = solve();
		if (ans != 0) { target = cnt; break; }
	}

	if (ans == -1) cout << "Inconsistency found after " << target << " relations.";
	else if (ans == 0) cout << "Sorted sequence cannot be determined.";
	else {
		cout << "Sorted sequence determined after " << target << " relations: ";
		for (int i = 0; i < n; i ++) cout << (char) (q[i] + 'A');
	}
	cout << "\n";
	return 0;
}