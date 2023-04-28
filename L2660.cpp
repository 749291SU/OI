#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL cal(LL a, LL b) {
	if (b == 0) return 0;
	return a / b * 4 * b + cal(b, a % b);	
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	LL x, y; cin >> x >> y;
	if (x < y) swap(x, y);
	cout << cal(x, y) << "\n";
	return 0;
}