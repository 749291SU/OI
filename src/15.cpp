#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;

const int N = 51;
int n, a, b;
vector<int> f[N][N][N];
// LL f[N][N][N];

vector<int> add(vector<int>& a, vector<int>& b) {
	vector<int> res;
	int t = 0;
	for (int i = 0; i < a.size() || i < b.size(); i ++) {
		int v1 = i < a.size() ? a[i] : 0, v2 = i < b.size() ? b[i] : 0;
		t += v1 + v2;
		res.push_back(t % 10);
		t /= 10;
	}
	if (t) res.push_back(1);
	return res;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> a >> b;
	f[0][0][0] = vector<int>(1, 1);
	vector<int> ans;
	// f[0][0][0] = 1;
	// LL ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j <= a; j ++) {
			for (int k = 0; k <= b; k ++) {
				for (int p = 0; p <= j; p ++) {
					for (int q = 0; q <= k; q ++) {
						f[i][j][k] = add(f[i][j][k], f[i - 1][j - p][k - q]);
						// f[i][j][k] += f[i - 1][j - p][k - q];
					}
				}	
				// if (i == n) ans += f[i][j][k];
				if (i == n) ans = add(ans, f[i][j][k]);
			}
		}
	}	
	for (int i = ans.size() - 1; i >= 0; i --) cout << ans[i];
	cout << "\n";
	// cout << ans << "\n";
	return 0;
}