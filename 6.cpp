#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 3e5 + 10;
int n;

long long a[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	int x;
	while (T --) {
		cin >> n;
		for (int i = 0; i < n; i ++) cin >> a[i];
		if (n & 1) { cout << "Yes" << "\n"; continue; }
		for (int i = 1; i < n - 1; i ++) {
			if (i & 1) {
				if (a[i] < a[i - 1]) { a[i + 1] += a[i - 1] - a[i]; a[i] = a[i - 1]; }
			}
			else a[i] -= a[i - 1] - a[i - 2];
		}
		cout << (a[n - 1] < a[n - 2] ? "No" : "Yes") << "\n";
	}
	return 0;
}