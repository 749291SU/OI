#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int M = 2e4 + 10, S = 110, N = 110;
int s, n, m;
int d[M];
int a[N][S];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> s >> n >> m;
	int x;
	for (int i = 0; i < s; i ++) {
		for (int j = 0; j < n; j ++) {
			cin >> a[j][i];
		}
	}	

	for (int i = 0; i < n; i ++) sort(a[i], a[i] + s);

	for (int i = 0; i < n; i ++) {
		for (int j = m; j >= 0; j --) {
			for (int k = 0; k < s && j > a[i][k] * 2; k ++) {
				d[j] = max(d[j], d[j - a[i][k] * 2 - 1] + (k + 1) * (i + 1));	
			}
		}
	}	
	cout << d[m] << "\n";	
	return 0;
}