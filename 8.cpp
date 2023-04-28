#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int x, res = 0;
	while (n --) {
		cin >> x;
		res ^= x;
	}
	cout << res << "\n";
	return 0;
}