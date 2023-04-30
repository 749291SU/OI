struct LCA {
	G* g;
	std::vector<std::vector<int>> fa;
	std::vector<int> depth, lg;
	
	LCA() { }
	LCA (G* g, int root) : g(g) {
		depth = std::vector<int> (g->n + 1);
		lg = std::vector<int> (g->n + 1);		
		fa = std::vector<std::vector<int>> (g->n + 1, std::vector<int>(log2(g->n) + 1));
		init(root);
	}

	inline void dfs(int x, int f) {
		fa[x][0] = f; depth[x] = depth[f] + 1;
		for (int i = 1; i < lg[depth[x]]; i ++) {
			fa[x][i] = fa[fa[x][i - 1]][i - 1];
		}
		for (int i = g->h[x]; i != -1; i = g->ne[i]) {
			int j = g->e[i];
			if (j != f) dfs(j, x);
		}
	}

	inline void init(int root) {
		for (int i = 1; i <= g->n; i ++) {
			lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
		}
		dfs(root, 0);
	}

	inline int solve(int a, int b) {
		if (depth[a] < depth[b]) std::swap(a, b);
		
		while (depth[a] > depth[b]) {
			a = fa[a][lg[depth[a] - depth[b]] - 1];		
		}	
		if (a == b) return a;

		for (int i = lg[depth[a]] - 1; i >= 0; i --) {
			if (fa[a][i] != fa[b][i]) {
				a = fa[a][i]; b = fa[b][i];
			}
		}
		return fa[a][0];
	}	
};
