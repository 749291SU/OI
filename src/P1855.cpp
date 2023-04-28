#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int M = 210;

int n, m, t;
int d[M][M];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> t;
	int mi, ti;

	while (n --) {
		cin >> mi >> ti;
		for (int j = m; j >= 0; j --) {
			for (int k = t; k >= 0; k --) {
				if (j >= mi && k >= ti) {
					d[j][k] = max(d[j][k], d[j - mi][k - ti] + 1);
				}
			}
		}	
	}	
	cout << d[m][t] << "\n";
	return 0;
}