#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;
const int N = 51;
int n;

int a[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	LL ans = 1;
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];

	sort(a, a + n);

	for (int i = 0; i < n; i ++) {
		if (a[i] - i <= 0) { cout << "0"; return 0; }
		ans = ans * (a[i] - i) % MOD;
	}
	cout << ans << "\n";
	return 0;
}