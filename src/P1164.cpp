#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int M = 1e4 + 10;
int n, m;

int d[M];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int x;
	d[0] = 1;
	while (n --) {
		cin >> x;
		for (int j = m; j >= 0; j --) {
			if (j >= x) d[j] += d[j - x];
		}
	}	
	cout << d[m] << "\n";
	
	return 0;
}