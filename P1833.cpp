#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10, M = 1e3 + 10;
int n, m;

struct Node {
	int v, w, p;
	bool operator < (const Node& ths) const {
		return p < ths.p;
	}
} obs[N];
int d[M], g[M], q[M];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string start, end;	
	cin >> start >> end >> n;
	int p1 = find(start.begin(), start.end(), ':') - start.begin();
	int p2 = find(end.begin(), end.end(), ':') - end.begin();
	int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	for (int i = 0; i < p1; i ++) t1 = t1 * 10 + start[i] - '0';
	t1 *= 60;
	for (int i = 0; i < p2; i ++) t3 = t3 * 10 + end[i] - '0';
	t3 *= 60;
	for (int i = p1 + 1; i < start.size(); i ++) t2 = t2 * 10 + start[i] - '0';	
	for (int i = p2 + 1; i < end.size(); i ++) t4 = t4 * 10 + end[i] - '0';	
	m = t3 + t4 - t1 - t2;

	for (int i = 0; i < n; i ++) {
		cin >> obs[i].v >> obs[i].w >> obs[i].p;
	}	

	sort(obs, obs + n);

	for (int i = 0; i < n; i ++) {
		if (obs[i].p == 0) {
			for (int j = 0; j <= m; j ++) {
				if (j >= obs[i].v) d[j] = max(d[j], d[j - obs[i].v] + obs[i].w);
			}
		}
		else {
			int v = obs[i].v, w = obs[i].w, s = obs[i].p;	
			memcpy(g, d, sizeof d);
			for (int j = 0; j < v; j ++) {
				int hh = 0, tt = -1;
				for (int k = j; k <= m; k += v) {
					if (hh <= tt && q[hh] < k - s * v) hh ++;
					while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w) tt --;		
					q[++ tt] = k;
					d[k] = max(d[k], g[q[hh]] + (k - q[hh]) / v * w);
				}	
			}
		}
	}

	cout << d[m] << "\n";
	return 0;
}