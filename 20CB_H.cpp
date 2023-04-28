#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e3 + 10;
int n;
int a[N];
int b[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	int s, t, e;
	for (int i = 0; i < n; i ++) {
		cin >> s >> t >> b[i];
		a[i] = s + t + b[i];
	}

	LL res = 0;

	sort(a, a + n);

	for (int i = 0; i < n; i ++) {
		res += a[i] * (n - i);
		res -= b[i];	
	}
	cout << res << "\n";
	return 0;
}