#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int V = 2e4 + 10;
int v, n;

int d[V];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> v >> n;
	int vv;
	while (n --) {
		cin >> vv;
		for (int j = v; j >= 0; j --) {
			if (j >= vv) d[j] = max(d[j], d[j - vv] + vv);
		}	
	}	
	cout << v - d[v] << "\n";
	return 0;
}