#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T --) {
		long long n; cin >> n;
		if (n == 4) cout << "5";
		else if (n == 10) cout << "11";
		else cout << n - 1;	
		cout << "\n";
	}
	return 0;
}