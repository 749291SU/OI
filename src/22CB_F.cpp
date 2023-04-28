#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int mon[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
int pre[13];

const int N = 1e3 + 10, M = 6e3 + 10;
int n, m, k;

struct Node {
	int d, v;
	bool operator < (const Node& ths) const {
		return d < ths.d;
	}
} obs[N];

bool f[N][M];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	pre[0] = 0;
	for (int i = 1; i <= 12; i ++) pre[i] = pre[i - 1] + mon[i];
	cin >> n >> m >> k;
	
	int mm, dd;
	int maxv = 0;

	obs[0].d = -360;
	for (int i = 1; i <= n; i ++) {
		cin >> mm >> dd >> obs[i].v;
		obs[i].d = pre[mm - 1] + dd;
		maxv = max(maxv, obs[i].v);
	}

	sort(obs, obs + n + 1);

	f[0][0] = true;
	int p = 0;
	for (int i = 1; i <= n; i ++) {
		while (obs[p].d + k <= obs[i].d) p ++;
		if (obs[p].d + k > obs[i].d) p --;
		for (int j = 0; j <= m + maxv; j ++) {
			f[i][j] = f[i - 1][j];
			if (j >= obs[i].v) f[i][j] |= f[p][j - obs[i].v];		
		}
	}	

	int ans = 0x3f3f3f3f;
	for (int i = m; i >= 0; i --) {
		if (f[n][i]) { ans = min(ans, i); break; }
	}
	for (int i = m + 1; i <= m + maxv; i ++) {
		if (f[n][i]) { ans = min(ans, i); break; }
	}
	cout << ans << "\n";
	return 0;
}