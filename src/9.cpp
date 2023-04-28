#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long n; cin >> n;
	long long t1 = n % (1 << 16), t2 = n / (1 << 16);
	cout << t1 * (1 << 16) + t2 << "\n";
	return 0;
}