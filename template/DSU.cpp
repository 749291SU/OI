struct DSU {
	std::vector<int> fa, siz;
	DSU(int n) : fa(n), siz(n, 1) { std::iota(fa.begin(), fa.end(), 0); }
	int leader(int x) {
		return fa[x] == x ? x : fa[x] = leader(fa[x]);	
	}
	bool same(int x, int y) { return leader(x) == leader(y); }
	bool merge(int x, int y) {
		x = leader(x); y = leader(y);
		if (x == y) return false;
		siz[x] += siz[y];			
		fa[y] = x;
		return true;
	}
	int size(int x) { return siz[leader(x)]; }
};
