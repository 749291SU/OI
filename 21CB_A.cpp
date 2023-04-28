#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cout << 25 << "\n";
	return 0;
}