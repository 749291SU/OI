#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

string s;
vector<char> b[26];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (getline(cin, s) && s != "0") {
		for (int i = 0; i < 26; i ++) b[i].clear();
		auto _not = [] (char c) -> bool {
			return c < 'A' || (c > 'Z' && c < 'a') || c > 'z';
		};
		for (int i = 0; i < s.size(); i ++) {
			if (!_not(s[i])) {
				if (s[i] >= 'a') b[s[i] - 'a'].push_back(s[i]);
				else b[s[i] - 'A'].push_back(s[i]);
			}
		}

		for (int i = 0, j = 0, k = 0; i < s.size(); i ++) {
			if (_not(s[i])) { cout << s[i]; continue; }
			if (j < 26 && k == b[j].size()) { j ++; k = 0; }	
			while (j < 26 && k == b[j].size()) j ++;
			if (j < 26) cout << b[j][k ++];
		}			
		cout << "\n";
	}
	return 0;
}