#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	long long ans = 0;
	for (int i = 1, j; i <= n; i = j + 1) {
		j = n / (n / i);	
		ans += (j - i + 1) * n / i;
	}
	cout << ans << "\n";
	return 0;
}