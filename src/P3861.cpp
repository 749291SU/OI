#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using i64 = long long;

const int MOD = 998244353;
const int N = 1e6 + 10;

i64 n;
i64 fa[11000];
int pos1[N], pos2[N];
int d[11001][11001];

std::unordered_map<i64, int> mm;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int T; std::cin >> T;
	while (T --) {
		std::cin >> n;
		if (mm[n]) {
			std::cout << mm[n] << "\n";
			continue;
		}

		int s = 0;
		for (int i = 1; i <= n / i; i ++) {
			if (n % i == 0) {
				fa[++ s] = i;
				if (n / i != i) fa[++ s] = n / i;
			}	
		}

		std::sort(fa + 1, fa + s + 1);

		for (int i = 0; i <= s; i ++) {
			for (int j = 0; j <= s; j ++) d[i][j] = 0;
		}

		for (int i = 1; i <= s; i ++) {
			d[i][i] = 1;
			if (fa[i] <= n / fa[i]) pos1[fa[i]] = i;
			else pos2[n / fa[i]] = i;	
		}

		for (int i = 1; i <= s; i ++) {
			for (int j = 1; j <= s; j ++) {
				d[i][j] += d[i][j - 1];
				if (i <= j) continue;

				if (fa[i] % fa[j] == 0) {
					i64 t = fa[i] / fa[j];
					d[i][j] += t <= n / t ? d[pos1[t]][j - 1] : d[pos2[n / t]][j - 1];
				}
				d[i][j] %= MOD;
			}
		}

		mm[n] = d[s][s] - 1;	
		std::cout << d[s][s] - 1 << "\n";
	}
	return 0;
}