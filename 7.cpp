#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e3 + 10;
int n, m;

int g[N][N];
int d[N];
bool in[N];
int tt[N];

int solve() {
	memset(in, false, sizeof in);
	int top, res = -1;
	do {
		top = 0;
		for (int i = 1; i <= n; i ++) {
			if (d[i] == 0 && !in[i]) {
				tt[++ top] = i; in[i] = true;
			}
		}

		for (int i = 1; i <= top; i ++) {
			for (int j = 1; j <= n; j ++) {
				if (g[tt[i]][j]) d[j] --;
			}
		}
		res ++;
	} while (top);
	return res;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int s, t;
	while (m --) {
		cin >> s;
		memset(in, false, sizeof in);
		int mit = 0x3f3f3f3f, mat = -0x3f3f3f3f;
		while (s --) {
			int t; cin >> t;
			in[t] = true;
			mit = min(mit, t); mat = max(mat, t);
		}
		for (int i = mit; i <= mat; i ++) {
			if (in[i]) {
				for (int j = mit + 1; j <= mat - 1; j ++) {
					if (!in[j] && !g[i][j]) { g[i][j] = 1; d[j] ++; }
				}
			}
		}
	}	
	cout << solve() << "\n";
	return 0;
}