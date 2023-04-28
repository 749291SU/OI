#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 5e5 + 10, M = 1e6 + 10;
int n, m, s;

int e[M], ne[M], h[N], idx;

void add(int a, int b) {
	e[idx] = b; ne[idx] = h[a]; h[a] = idx ++;
}

int fa[N];
int vis1[N], vis2[N];

void dfs(int x, int f) {
	for (int i = h[x]; i != -1; i = ne[i]) {
		int j = e[i];
		if (j == f) continue;	
		fa[j] = x;
		dfs(j, x);
	}	
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(h, -1, sizeof h);
	cin >> n >> m >> s;
	int a, b;
	for (int i = 0; i < n - 1; i ++) {
		cin >> a >> b;
		add(a, b); add(b, a);
	}

	fa[s] = 0;
	dfs(s, 0);

	for (int i = 1; i <= n; i ++) vis1[i] = vis2[i] = m;	
	while (m --) {
		cin >> a >> b;
		int ans;
		while (b | a) {
			vis1[a] = vis2[b] = m;
			if (vis1[b] == m) { ans = b; break; }
			if (vis2[a] == m) { ans = a; break; }
			a = fa[a]; b = fa[b];
		}
		cout << ans << "\n";
	}

	return 0;
}