#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
int n, q;
int a[N], b[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> q;
	int ma;
	for (int i = 0; i < n; i ++) { cin >> a[i]; b[a[i]] ++; ma = max(ma, a[i]); }

	sort(a, a + n);

	int p;
	while (q --) {
		cin >> p;
		bool flag = false;
		for (int i = 0; i < n; i ++) {
			if (a[i] * p > ma) break;
			if (b[a[i] * p]) { flag = true; break; }	
		}	
		cout << (flag ? "YES" : "NO") << "\n";
	}
	return 0;
}