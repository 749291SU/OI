#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int T; std::cin >> T;
	std::string a, b, c;
	while (T --) {
		std::cin >> a >> b >> c;
		bool flag = true;
		for (int i = 0; i < 4; i ++) {
			std::unordered_map<int, int> mm;
			mm[a[i]] ++;
			mm[a[i + 4]] ++;
			mm[a[i + 8]] ++;

			mm[b[i]] ++;
			mm[b[i + 4]] ++;

			mm[c[i]] ++;

			if (mm['G'] != 3 || mm['R'] != 2 || mm['Y'] != 1) {
				flag = false;
				break;
			}
		}
		std::cout << (flag ? "YES" : "NO") << "\n";
	}
	return 0;
}