struct G {
	int n, m;
	int idx;
	std::vector<int> e, ne, w, h;
	std::vector<int> in, out;

	G () { }
	G (int n, int m) : n(n), m(m), e(m), ne(m), w(m), in(n + 1), out(n + 1), h(n + 1, -1) { }	

	void add(int a, int b) {
		e[idx] = b; ne[idx] = h[a]; h[a] = idx ++;
		in[b] ++; out[a] ++;
	}	

	void add(int a, int b, int c) {
		w[idx] = c;	
		add(a, b);
	}
};