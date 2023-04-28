#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 256, M = 6e5 + 10;
const LL INF = 1e18;
int n;
LL m;

LL d[M];
int s[N], v[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int sumv = 0;
	for (int i = 0; i < n; i ++) cin >> s[i];
	for (int i = 0; i < n; i ++) { cin >> v[i]; sumv += v[i] * s[i]; }

	for (int i = 0; i <= sumv; i ++) d[i] = 1;
	for (int i = 0; i < n; i ++) {
		int _v = v[i], _s = s[i];
		for (int j = sumv; j >= 0; j --) {
			for (int k = 0; k <= min(s[i], j / v[i]); k ++) {
				d[j] = max(d[j], d[j - k * v[i]] * max(1, k));	
			}	
		}
	}
	int ans;
	for (int i = 0; i <= sumv; i ++) {
		if (d[i] >= m) {
			ans = i; break;
		}
	}
	cout << ans << "\n";
	return 0;
}