#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b;
	cin >> a >> b;
	cout << (long long) (a - 1) * (b - 1) - 1 << "\n";				
	return 0;
}