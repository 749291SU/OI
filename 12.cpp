#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string s;

void build(int& i) {
	char c = s[i ++];
	if (c == '#') return ;
	build(i);
	cout << c << " ";
	build(i);
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> s;
	int t = 0;
	build(t);

	return 0;
}