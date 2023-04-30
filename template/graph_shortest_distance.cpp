#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using i64 = long long;

const int INF = 0x3f3f3f3f;

struct G {
	int n, m;
	int idx;
	std::vector<int> e, ne, w, h;
	std::vector<int> in, out;

	G () { }
	G (int n, int m) : n(n), m(m), e(m), ne(m), w(m), in(n + 1), out(n + 1), h(n + 1, -1) { }	

	inline void add(int a, int b) {
		e[idx] = b; ne[idx] = h[a]; h[a] = idx ++;
		in[b] ++; out[a] ++;
	}	

	inline void add(int a, int b, int c) {
		w[idx] = c;	
		add(a, b);
	}
};

struct GSD {
	G* g;
	
	GSD() { }
	GSD(G* g) : g(g) { };					
	
	inline std::vector<int> spfa(int src) {
		int hh = 0, tt = -1;
		std::vector<int> dist(g->n + 1, INF);	
		std::vector<bool> st(g->n + 1, false);	
		std::vector<int> q(g->n * g->n);
		q[++ tt] = src; st[src] = true;

		while (hh <= tt) {
			int u = q[hh ++]; st[u] = false;
			for (int i = g->h[u]; i != -1; i = g->ne[i]) {
				int j = g->e[i];	
				if (dist[j] > dist[u] + g->w[i]) {
					dist[j] = dist[u] + g->w[i];
					if (!st[j]) { st[j] = true; q[++ tt] = j; }
				}
			}		
		}
		return dist;
	}

	inline int spfa(int src, int dst) {
		return spfa(src)[dst];	
	}

	inline std::vector<int> dijkstra_heap_optimize(int src) {
		
	}	

	inline int dijkstra_heap_optimize(int src, int dst) {
		return dijkstra_heap_optimize(src)[dst];	
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

		

	return 0;
}
