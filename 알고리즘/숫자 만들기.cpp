#define _CRT_SECURE_NO_WARNINGS

#define INF 2e9;
#include <iostream>
#include <math.h>

using namespace std;

int T;
int C[4];
int input[13], MAX,MIN,n;

void recursion(int cnt , int now, int remain[4]) {

	if (n == cnt) {
		MAX = fmax(now, MAX);
		MIN = fmin(now, MIN);
		return;
	}

	if (remain[0] > 0) {
		remain[0]--;
		recursion(cnt + 1, now + input[cnt+1], remain);
		remain[0]++;
	}
	if (remain[1] > 0) {
		remain[1]--;
		recursion(cnt + 1, now - input[cnt + 1], remain);
		remain[1]++;
	}
	if (remain[2] > 0) {
		remain[2]--;
		recursion(cnt + 1, now * input[cnt + 1], remain);
		remain[2]++;
	}
	if (remain[3] > 0) {
		remain[3]--;
		recursion(cnt + 1, now / input[cnt + 1], remain);
		remain[3]++;
	}
	//recursion(cnt, now , remain);
}

int main() {
	scanf("%d", &T);
	for (int k = 1; k <= T; k++) {
		
		scanf("%d", &n);
		for (int i = 0; i < 4; i++)
			scanf("%d", &C[i]);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &input[i]);
		}
		MAX = -INF;
		MIN = INF;
		recursion(1, input[1], C);

		printf("#%d %d\n", k, MAX-MIN);

	}
}