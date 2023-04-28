#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int T = 1e3 + 10;
int t, m;
int d[T];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t >> m;
	int ti, va;
	while (m --) {
		cin >> ti >> va;
		for (int j = t; j >= 0; j --) {
			if (j >= ti) d[j] = max(d[j], d[j - ti] + va);
		}	
	}
	cout << d[t] << "\n";
	return 0;
}