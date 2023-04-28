#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int T = 410;
int n, h, t;
int d[T][T];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> h >> t >> n;
	int hi, ti, ki;
	while (n --) {
		cin >> hi >> ti >> ki;
		for (int j = h; j >= 0; j --) {
			for (int k = t; k >= 0; k --) {
				if (j >= hi && k >= ti) {
					d[j][k] = max(d[j][k], d[j - hi][k - ti] + ki);
				}
			}
		}
	}
	
	cout << d[h][t] << "\n";
	return 0;
}