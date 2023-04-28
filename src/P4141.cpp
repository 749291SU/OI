#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2001;
int n, m;
int a[N];
int d1[N][N], d2[N][N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	d1[0][0] = 1; d2[n + 1][0] = 1;
	for (int i = 1; i <= n; i ++) { 
		cin >> a[i];
		for (int j = 0; j <= m; j ++) {
			d1[i][j] = d1[i - 1][j] % 10;
			if (j >= a[i]) d1[i][j] = (d1[i][j] + d1[i - 1][j - a[i]]) % 10;
		}
	}

	for (int i = n; i > 0; i --) {
		for (int j = 0; j <= m; j ++) {
			d2[i][j] = d2[i + 1][j] % 10;
			if (j >= a[i]) d2[i][j] = (d2[i][j] + d2[i + 1][j - a[i]]) % 10;
		}	
	}
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			int tmp = 0;
			for (int k = 0; k <= j; k ++) {
				tmp = (tmp + d1[i - 1][k] * d2[i + 1][j - k]) % 10;
			}
			cout << tmp;
		}
		cout << "\n";
	}
	return 0;
}