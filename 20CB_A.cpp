#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int ans = 0;
	for (int i = 1; i <= 2020; i ++) {
		bool flag = false;
		int j = i;
		while (j) {
			if (j % 10 == 2) {
				flag = true;
				break;
			}
			j /= 10;
		}
		if (flag) ans ++;
	}	
	cout << ans << "\n";
	return 0;
}