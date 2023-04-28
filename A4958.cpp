#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];
int tmp[10];
int d[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];

	int ans = 1;
	for (int i = 0; i < n; i ++) {
		int x = 0, t = a[i];
		while (t) {
			x = t % 10;
			t /= 10;
		}	
		d[i] = max(d[i], tmp[x] + 1);	
		tmp[a[i] % 10] = max(tmp[a[i] % 10], d[i]);
		ans = max(ans, d[i]);
	}
	cout << n - ans << "\n";
	return 0;
}