#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] < 'a') cout << s[i];
		else cout << (char) (s[i] - 32);
	}		
	cout << "\n";
	return 0;
}