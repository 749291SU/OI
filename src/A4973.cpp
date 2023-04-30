#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using i64 = long long;

std::unordered_map<std::string, int> mm;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int cnt = 1;
	int n; std::cin >> n;
	std::string s;
	std::vector<std::string> ans(n);	

	for (int i = 0; i < n; i ++) {
		std::cin >> s;
		int t = mm[s];	
		ans[t] = ""; ans[cnt] = s;
		mm[s] = cnt ++;
	}	
	for (int i = cnt - 1; i > 0; i --) {
		if (ans[i] != "" ) std::cout << ans[i] << "\n";
	}
	return 0;
}