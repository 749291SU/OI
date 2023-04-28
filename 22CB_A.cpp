#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long f[2023][11][2023];

long long dfs(int start, int v, int h) {
	long long& ff = f[v][h][start];		
	if (ff >= 0) return ff;
	if (v == 0 && h == 0) return ff = 1;
	if (v == 0 || h == 0) return ff = 0;

	ff = 0;
	for (int i = start; i <= v / h; i ++) {
		ff += dfs(i + 1, v - i, h - 1);
	}
	return ff;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	memset(f, -1, sizeof f);

	cout << dfs(1, 2022, 10) << "\n";

	return 0;
}