#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 51;
int n;
int a[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;		
	while (T --) {
		cin >> n;
		for (int i = 0; i < n; i ++) cin >> a[i];

		sort(a, a + n);

		int ans = 0;
		for (int i = 0; i < n; i ++) {
			for (int j = i; j < n; j ++) {
				int t = a[i] + a[j];
				int cnt = upper_bound(a, a + n, t) - lower_bound(a, a + n, t);
				if (j != i) ans += cnt * 2;
				else ans += cnt;
			}
		}
		cout << ans << "\n";
	}	
	return 0;
}