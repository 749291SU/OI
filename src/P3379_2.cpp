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

int lg[N];
int fa[N][25], depth[N];

void dfs(int x, int f) {
	fa[x][0] = f; depth[x] = depth[f] + 1;

	for (int i = 1; i < lg[depth[x]]; i ++) {
		fa[x][i] = fa[fa[x][i - 1]][i - 1];	
	}

	for (int i = h[x]; i != -1; i = ne[i]) {
		int j = e[i];
		if (j != f) dfs(j, x);
	}	
}

int LCA(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);	

	while (depth[a] > depth[b]) {
		a = fa[a][lg[depth[a] - depth[b]] - 1];	
	}

	if (a == b) return a;	

	for (int i = lg[depth[a]] - 1; i >= 0; i --) {
		if (fa[a][i] != fa[b][i]) { a = fa[a][i]; b = fa[b][i]; }	
	}
	return fa[a][0];
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

	for (int i = 1; i <= n; i ++) lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
	dfs(s, 0);

	while (m --) {
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}

	return 0;
}