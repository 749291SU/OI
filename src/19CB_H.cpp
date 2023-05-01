#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

using i64 = long long;

i64 t[5] = {177147, 2187, 27, 531441, 81};

struct Node {
	int a, b, c;
	Node() {}
	Node(int a, int b, int c) : a(a), b(b), c(c) { } 
	inline bool operator == (const Node& ths) const {
		return a == ths.a && b == ths. b && c == ths.c;
	}
};

Node target(531440, 3280, 0);

bool solve(int a, int b, int c) {
	std::unordered_map<i64, int> mm;
	std::queue<Node> q;	q.push(Node(a, b, c));
	mm[a * t[3] + b * t[4] + c] = 1;
	while (q.size()) {
		Node u = q.front(); q.pop();
		if (u == target) return true;

		int a = u.a, b = u.b, c = u.c;	
		int la_a = a % 3, la_b = b % 3, la_c = c % 3;
		int fi_a = a / t[0], fi_b = b / t[1], fi_c = c / t[2];

		Node v1(a / 3 + la_a * t[0], b / 3 + la_b * t[1], c / 3 + la_c * t[2]);
		Node v2((a - fi_a * t[0]) * 3 + fi_a, (b - fi_b * t[1]) * 3 + fi_b, (c - fi_c * t[2]) * 3 + fi_c);
		Node v3(a + (fi_b - fi_a) * t[0], b + (fi_c - fi_b) * t[1], c + (fi_a - fi_c) * t[2]);
		i64 t1 = v1.a * t[3] + v1.b * t[4] + v1.c, t2 = v2.a * t[3] + v2.b * t[4] + v2.c, t3 = v3.a * t[3] + v3.b * t[4] + v3.c;

		if (!mm.count(t1)) { q.push(v1); mm[t1] = 1; }
		if (!mm.count(t2)) { q.push(v2); mm[t2] = 1; }
		if (!mm.count(t3)) { q.push(v3); mm[t3] = 1; }
	}
	return false;
}
inline int getv(char c) {
	if (c == 'Y') return 0;
	if (c == 'R') return 1;
	return 2;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int T; std::cin >> T;	
	char cc;
	int a, b, c;
	while (T --) {
		a = b = c = 0;
		for (int i = 0; i < 12; i ++) {
			std::cin >> cc;
			a = a * 3 + getv(cc);
		}
		for (int i = 0; i < 8; i ++) {
			std::cin >> cc;
			b = b * 3 + getv(cc);
		}

		for (int i = 0; i < 4; i ++) {
			std::cin >> cc;
			c = c * 3 + getv(cc);
		}
		// std::cout << a << " " << b << " " << c << "\n";
		std::cout << (solve(a, b, c) ? "YES" : "NO") << "\n";
	}
	return 0;
}