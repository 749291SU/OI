#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using i64 = long long;

const int INF = 0x3f3f3f3f;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int n, m;
	std::string s, t;	
	std::cin >> s >> t;
	n = s.size(); m = t.size();

	std::vector<int> d(m + 1, INF);

	d[0] = 0;

	for (int i = 1; i <= n; i ++) {
		for (int j = m; j >= 1; j --) {
			d[j] = std::min(d[j], d[j - 1] + (s[i - 1] != t[j - 1]));
		}	
	}
	std::cout << d[m] << "\n";
	return 0;
}