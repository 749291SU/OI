#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 18;

int n;
LL d[N];
LL f[110][110];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	d[0] = 1;
	int a, b;

	LL t; cin >> t >> a >> b;
	for (int i = 1; i < 18; i ++) d[i] = d[i - 1] * 10;

	int p = 0;
	while (t) {
		int cur = t % 10;
		for (int j = a; j >= 0; j --) {
			for (int k = b; k >= 0; k --) {
				int t = min(9, cur + j);
				LL res = 0;
				res = max(res, f[j + cur - t][k] + t * d[p]);
				if (cur + 1 <= k) res = max(res, f[j][k - cur - 1] + 9 * d[p]);	
				f[j][k] = res;
			}
		}
		t /= 10; p ++;
	}
	cout << f[a][b] << "\n";
	return 0;
}	