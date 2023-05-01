#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>

using i64 = long long;

struct Node {
	int x, y, z;	
	Node() {}
	Node(int x, int y, int z) : x(x), y(y), z(z) { }
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int T; std::cin >> T;	
	std::string a, b, c;
	std::string t1 ,t2, t3;
	std::vector<Node> d;
	while (T --) {
		std::cin >> a >> b >> c;
		for (int i = 0, j = 0, k = 0, p = 0; p < 24; i = (i + 1) % 4, j = (j + 1) % 8, k = (k + 1) % 12, p ++) {
			d.push_back(Node(k, j, i));
		}

		bool flag = true;
		for (i64 i = 0; i < pow(3, 24); i ++) {
			if (i > 1e7) break;
			t1 = a; t2 = b; t3 = c;
			i64 t = i;
			int cnt = 0;
			while (t) {
				int tmp = t % 10;
				int x = d[cnt].x, y = d[cnt].y, z = d[cnt].z;
				if (tmp == 1) {
					std::swap(t1[x], t2[y]);
					std::swap(t2[y], t3[z]);
				}
				else if (tmp == 2) {
					std::swap(t1[x], t3[z]);
					std::swap(t2[y], t3[z]);	
				}
				t /= 3; cnt ++;
			}	

			if (t1 == "GGGGGGGGGGGG" && t2 == "RRRRRRRR" && t3 == "YYYY") {
				flag = true;
				break;	
			}
		}
		std::cout << (flag ? "YES" : "NO") << "\n";
	}
	return 0;
}