#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10;
char s1[N], s2[N];
int f[N];

int main() {
	scanf("%s%s", s1, s2);
	int le1 = strlen(s1), le2 = strlen(s2);
	int ans = 0;
	for (int i = 0; i < le2; i ++) {
		for (int j = le1 - 1; j >= 0; j --) {
			if (s2[i] == s1[j] && s2[i] >= 'a' && s2[i] <= 'z') {
				f[j] = j > 0 ? f[j - 1] + 1 : 1;	
			}
			else f[j] = 0;
			ans = max(ans, f[j]);
		}
	}			
	printf("%d\n", ans);
	return 0;
}