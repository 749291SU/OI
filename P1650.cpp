#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int a[101], b[101];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	int x;
	for (int i = 0; i < n; i ++) {
		cin >> x;
		a[x] ++;
	}
	for (int i = 0; i < n; i ++) {
		cin >> x;
		b[x] ++;
	}

	int ans = 0, ans1;
	int i = 0;
	while (i <= 100) {
		if (a[i] == 0) { i ++ ; continue; }
		while (a[i]) {
			int t = -1;
			for (int j = i - 1; j >= 0; j --) {
				if (b[j]) { t = j; break; }
			}
			if (t != -1) { b[t] --; ans ++; }
			else break;
			a[i] --;
		}	
		i ++;
	}

	ans1 = n - ans;
	i = 0;
	while (i <= 100) {
		if (a[i] == 0) { i ++; continue; }
		ans1 -= min(a[i], b[i]);	
		i ++;
	}	
	cout << (ans - ans1) * 200 << "\n";
	return 0;
}