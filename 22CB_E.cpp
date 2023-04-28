#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10, M = 2e4 + 10;
int n, m;

int cost[N];
int e[M], ne[M], w[M], h[N], idx;

void add(int a, int b, int c) {
	e[idx] = b; ne[idx] = h[a]; w[idx] = c; h[a] = idx ++;	
}

int q[N], dist[N];
bool st[N];

int spfa() {
	int hh = 0, tt = -1;
	memset(dist, 0x3f, sizeof dist);
	q[++ tt] = 1;
	dist[1] = 0; st[1] = true;

	while (hh <= tt) {
		int u = q[hh ++];
		st[u] = false;

		for (int i = h[u]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[u] + w[i] + cost[u]) {
				dist[j] = dist[u] + w[i] + cost[u];
				if (!st[j]) { q[++ tt] = j; st[j] = true; }
			}
		}
	}
	return dist[n];
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(h, -1, sizeof h);

	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> cost[i];
	cost[1] = 0;

	int a, b, c;
	while (m --) {
		cin >> a >> b >> c;
		add(a, b, c); add(b, a, c);
	}	

	cout << spfa() << "\n";		

	return 0;
}