#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int N, a[8],ans, tot;

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", a + i);
	}
	sort(a, a + N);
	do{
	for (int i = 0; i < N-1; i++) {
		tot += abs(a[i] - a[i + 1]);
	}
	ans = max(tot, ans);
	tot = 0;
	} while (next_permutation(a, a + N));

	printf("%d", ans);

	return 0;
}