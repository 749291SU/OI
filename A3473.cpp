#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T --) {
		int a; cin >> a;
		if (a & 1) cout << "0 0";	
		else cout << (a - 1) / 4 + 1 << " " << a / 2;
		cout << "\n";
	}		

	return 0;
}