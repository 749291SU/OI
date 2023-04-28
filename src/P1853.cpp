#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int N = 41, D = 11;
int s, n, d;

int v[D], w[D];
unordered_map<LL, LL> mm;
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> s >> n >> d;
	for (int i = 0; i < d; i ++) { cin >> v[i] >> w[i]; v[i] /= 1000; }

	LL ans = s;
	LL prev = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < d; j ++) {
			for (LL k = prev / 1000; k <= ans / 1000; k ++) {
				if (k >= v[j]) mm[k] = max(mm[k], mm[k - v[j]] + w[j]);
			}
		}
		prev = ans;
		ans += mm[ans / 1000];
	}
	cout << ans << "\n";
	return 0;
}