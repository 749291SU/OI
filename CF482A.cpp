#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	for (int i = 1; i < n - k; i ++) cout << i << " ";
	cout << n - k << " ";
	int pre = n - k;
	for (int i = k, j = 1; i >= 1; i --, j = -j) {
		cout << pre + i * j << " ";
		pre = pre + i * j;
	}
	cout << "\n";
	return 0;
}