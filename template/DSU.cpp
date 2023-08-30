
int fa[N], siz[N];
inline void init(int cc) {
	for (int i = 1; i <= cc; i ++) { fa[i] = i; siz[i] = 1; }
}
int leader(int x) {
	return fa[x] == x ? x : fa[x] = leader(fa[x]);	
}
inline bool merge(int x, int y) {
	x = leader(x); y = leader(y);
	if (x == y) return false;
	siz[y] += siz[x];			
	fa[x] = y;
	return true;
}
inline int size(int x) { return siz[leader(x)]; }
