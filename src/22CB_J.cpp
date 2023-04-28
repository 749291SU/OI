#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;
int n;

struct Node {
	int w, v;
	bool operator < (const Node& ths) const {
		return w + v < ths.w + ths.v;
	}
} obs[N];

int f[N][2 * N];
int roma[2 * N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	int ma = 0;
	for (int i = 0; i < n; i ++) { 
		cin >> obs[i].w >> obs[i].v;
		ma = 2 * obs[i].v;
	}

	sort(obs, obs + n);

	int ans = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = obs[i].v + obs[i].w; j >= obs[i].w; j --) {
			f[i][j] = roma[j - obs[i].w] + obs[i].v;
			roma[j] = max(roma[j], f[i][j]);
			ans = max(ans, f[i][j]);
		}
		for (int j = obs[i].v + obs[i].w + 1; j <= ma; j ++) { 
			f[i][j] = f[i][j - 1];
			roma[j] = max(roma[j], f[i][j]);	
		}
	}
	cout << ans << "\n";
	return 0;
}
