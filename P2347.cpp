#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int M = 1e3 + 10;
bool d[M];
int a[6] = {1, 2, 3, 5, 10, 20};
int s[6];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 6; i ++) cin >> s[i];

	d[0] = true;
	int ans = 0;
	for (int i = 0; i < 6; i ++) {
		for (int j = M; j >= 0; j --) {
			for (int k = 0; k <= min(s[i], j / a[i]); k ++) {
				d[j] = d[j] | d[j - k * a[i]];		
			}	
			if (i == 5 && d[j] && j) ans ++;
		}
	}	
	cout << "Total=" << ans << "\n";	
	return 0;
}