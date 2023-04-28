#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

const int N = 1e5 + 10;
int n;
LL t;
string s;
int num[N];

inline int f(LL x) {
	int res = 0;
	while (x && (!(x & 1ll))) {
		x >>= 1;
		res ++;
	}	
	return res;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> t >> s;

	for (int i = 1; i <= n; i ++) {
		num[i] = num[i - 1] + f(t - i + 1) - f(i);	
	}

	for (int i = n - 1; i > 0; i --) {
		for (int j = 0; j < i; j ++) {
			if (num[i - j] == 0) {
				s[i] = (s[i] - '0') ^ (s[j] - '0') + '0';
			}	
		}
	}
	cout << s << "\n";	
	return 0;
}