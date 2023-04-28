#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

string s;
vector<string> d[210];

unordered_map<string, int> mm;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long ans = 0; 
	cin >> s;
	for (int i = 0; i < s.size(); i ++) {
		string t(1, s[i]);	
		if (!mm.count(t)) { 
			mm[t] = 1; 
			ans ++;
			d[i].push_back(t);	
		}

		for (int j = 0; j < i; j ++) {
			if (s[i] <= s[j]) continue;
			for (int k = 0; k < d[j].size(); k ++) {
				string tt = t + d[j][k];	
				if (!mm.count(tt)) {
					mm[tt] = 1;
					ans ++;
					d[i].push_back(tt);
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}