#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int f[7][27];
string s;
int main() {
	cin.tie(0); cout.tie(0);

	cin >> s;
	if (s[0] < 'a' || s[0] > 'z') { cout << "0\n"; return 0;}
	int ans = 0;
	for (int i = 1; i <= 6; i ++) {
		for (int j = 26 - i; j >= 0; j --) {
			f[i][j] += f[i - 1][j + 1] + f[i][j + 1];
			if (i == 1) f[i][j] = 1;
			if (i < s.size() || (i == s.size() && j + 'a' < s[0])) ans += f[i][j]; 
		}	
	}
	// cout << f[3][0] << " " << f[3][1] << "\n";
	ans ++;
	// cout << ans << "\n";

	if (s.size() > 6) { cout << "0" << "\n"; return 0; }
	for (int i = 1; i < s.size(); i ++) {
		if (s[i] <= s[i - 1] || s[i] < 'a' || s[i] > 'z') {
			cout << "0" << "\n";
			return 0;
		}
	}

	for (int i = 1; i < s.size(); i ++) {
		for (int j = s[i - 1] + 1; j < s[i]; j ++) { 
			// cout << f[s.size() - i][j - 'a'] << "\n"; 
			ans += f[s.size() - i][j - 'a'];
		}
		// cout << ans << "\n";
	}
	cout << ans << "\n";
	return 0;
}