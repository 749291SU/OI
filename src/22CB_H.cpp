#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, bool> PII;

const int N = 1e5 + 10, M = 2e5 + 10;
int n, m;

int e[M], ne[M], h[N], idx;
void add(int a, int b) {
	e[idx] = b; ne[idx] = h[a]; h[a] = idx ++;
}

int d[N];
int dist[N], q[N];
bool st[N];

int spfa(int a, int b) {
	int hh = 0, tt = -1;
	memset(dist, 0x3f, sizeof dist);
	memset(st, false, sizeof st);
	dist[a] = 0; st[a] = true;
	q[++ tt] = a;
	while (hh <= tt) {
		int u = q[hh ++];
		st[u] = false;
		for (int i = h[u]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[u] + d[u]) {
				dist[j] = dist[u] + d[u];
				if (!st[j]) { st[j] = true; q[++ tt] = j; }
			}
		}
	}
	return dist[b];
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(h, -1, sizeof h);
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < n - 1; i ++) {
		cin >> a >> b;
		add(a, b); add(b, a);
		d[a] ++; d[b] ++;
	}	

	while (m --) {
		cin >> a >> b;
		cout << spfa(a, b) + d[b] << "\n";
	}		
	return 0;
}