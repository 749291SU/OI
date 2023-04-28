#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e3 + 10, MOD = 998244353;

int n, m, a, b;
int h1[N], t1[N];
int h2[N], t2[N];
int q1[N][N], q2[N][N];
LL g[N][N];
int q3[N], q4[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> a >> b;		

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) cin >> g[i][j];
	}

	LL ans = 0;
	memset(t1, -1, sizeof t1);	
	memset(t2, -1, sizeof t2);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			int& _h1 = h1[j], &_t1 = t1[j];
			int& _h2 = h2[j], &_t2 = t2[j];
			int x = g[i][j];
			while (_h1 <= _t1 && g[q1[j][_t1]][j] <= x) _t1 --;
			while (_h2 <= _t2 && g[q2[j][_t2]][j] >= x) _t2 --;
			q1[j][++ _t1] = i; q2[j][++ _t2] = i;
			if (q1[j][_h1] < i - a + 1) _h1 ++;
			if (q2[j][_h2] < i - a + 1) _h2 ++;

			// for (int k = _h1; k <= _t1; k ++) cout << q1[j][k] << " ";
			// for (int k = _h2; k <= _t2; k ++) cout << q2[j][k] << " ";
			// cout << "\n";	
		}
		// cout << "\n";

		int __h1 = 0, __t1 = -1, __h2 = 0, __t2 = -1;
		for (int j = 0; j < m; j ++) {
			int p1 = q1[j][h1[j]], p2 = q2[j][h2[j]];
			int x1 = g[p1][j], x2 = g[p2][j];
			while (__h1 <= __t1 && g[q1[q3[__t1]][h1[q3[__t1]]]][q3[__t1]] <= x1) __t1 --;
			while (__h2 <= __t2 && g[q2[q4[__t2]][h2[q4[__t2]]]][q4[__t2]] >= x2) {
				// cout << q4[__t2] << " " << q2[j][h2[q4[__t2]]] << "\n";
				// cout << j << " " << g[q2[j][h2[q4[__t2]]]][j] << "\n";
				__t2 --;
			}
			// cout << __h2 << " " << __t2 << "\n";
			// cout << x2 << "\n";
			q3[++ __t1] = j; q4[++ __t2] = j;	
			if (q3[__h1] < j - b + 1) __h1 ++;
			if (q4[__h2] < j - b + 1) __h2 ++;
			if (i >= a - 1 && j >= b - 1) {
				int maj = q3[__h1], mij = q4[__h2];
				int mahh = h1[maj], mihh = h2[mij];
				int mai = q1[maj][mahh], mii = q2[mij][mihh];
				// cout << i << " " << j << " " << g[mai][maj] << " " << g[mii][mij] << "\n";
				ans = (ans + g[mai][maj] * g[mii][mij]) % MOD;	
			}
			// cout << q4[__h2] << "\n";
			// for (int k = __h1; k <= __t1; k ++) cout << g[q1[q3[k]] << " ";
			// for (int k = __h2; k <= __t2; k ++) cout << g[q2[q4[k]][h2[q4[k]]]][q4[k]] << " ";
			// for (int k = __h2; k <= __t2; k ++) cout << q4[k] << " ";
			// cout << x1 << " " << x2 << "\n";
			// cout << __h2 << " " << __t2 << "\n";
			// cout << "\n";
		}
		// cout << "\n";
	}
	cout << ans << "\n";
	return 0;
}