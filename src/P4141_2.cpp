#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2001;
int n, m;
int a[N];
int f[N][2];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	f[0][0] = f[0][1] = 1;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		for (int j = m; j >= 0; j --) {
			if (j >= a[i]) f[j][0] = (f[j][0] + f[j - a[i]][0]) % 10;
		}
	}	

	for (int i = 0; i < n; i ++) {
		for (int j = 1; j <= m; j ++) {
			f[j][1] = j >= a[i] ? (f[j][0] - f[j - a[i]][1] + 10) % 10 : f[j][0];
			cout << f[j][1];
		}
		cout << "\n";
	}
	return 0;
}