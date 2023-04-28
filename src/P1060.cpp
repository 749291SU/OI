#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 3e4 + 10;
int n, m;

int d[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int v, p;		
	while (m --) {
		cin >> v >> p;
		for (int j = n; j >= 0; j --) {
			if (j >= v) d[j] = max(d[j], d[j - v] + v * p);
		}
	}
	cout << d[n] << "\n";
	return 0;
}