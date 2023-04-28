#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s;
	while (cin >> s && s != "0") {
		int ans = 0;
		for (int i = 0; i < s.size(); i ++) {
			ans += (s[i] - '0') * ((1 << ((int) s.size() - i)) - 1);
		}	
		cout << ans << "\n";
	}	

	return 0;
}