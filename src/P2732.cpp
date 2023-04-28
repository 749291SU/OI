#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int S = 106, INF = 0x3f3f3f3f;
int s, n, c, k, p, b;
int pp[S], obs[S][5], idx, cnt;
int need[5];
int f[S][6][6][6][6][6];
unordered_map<int, int> mm;

inline int get_sign(int x) {
	return mm.count(x) ? mm[x] : mm[x] = cnt ++;
}

int dp(int i, int t, int u, int v, int w, int x) {
	int& ff = f[i][t][u][v][w][x];
	if (ff >= 0) return ff;
	if (t + u + v + w + x == 0) return ff = 0;
	else if (i >= idx) return ff = INF;
	ff = INF;
	int ma = 0;
	if (obs[i][0] > 0) ma = max(ma, t / obs[i][0]);	
	if (obs[i][1] > 0) ma = max(ma, u / obs[i][1]);
	if (obs[i][2] > 0) ma = max(ma, v / obs[i][2]);
	if (obs[i][3] > 0) ma = max(ma, w / obs[i][3]);
	if (obs[i][4] > 0) ma = max(ma, x / obs[i][4]);

	for (int z = 0; z <= ma; z ++) {
		ff = min(ff, dp(i + 1, max(0, t - z * obs[i][0]), 
			max(0, u - z * obs[i][1]), max(0, v - z * obs[i][2]), 
			max(0, w - z * obs[i][3]), max(0, x - z * obs[i][4])) + pp[i] * z);
	}
	return ff;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(f, -1, sizeof f);
	cin >> s;
	for (int i = 0; i < s; i ++) {
		cin >> n;
		for (int j = 0; j < n; j ++) {
			cin >> c >> k;
			int sign = get_sign(c);
			obs[idx][sign] = k;
		}
		cin >> p;
		pp[idx ++] = p;
	}	

	cin >> b;
	for (int i = 0; i < b; i ++) {
		cin >> c >> k >> p;
		int sign = get_sign(c);
		need[sign] = k;
		obs[idx][sign] = 1;
		pp[idx ++] = p;
	}
	// for (int i = 0; i < idx; i ++) {
	// 	for (int j = 0; j < 5; j ++) cout << obs[i][j] << " ";
	// 	cout << pp[i] << "\n";
	// }	
	// for (int i = 0; i < 5; i ++) cout << need[i] << "\n";
	cout << dp(0, need[0], need[1], need[2], need[3], need[4]) << "\n";

	return 0;
}