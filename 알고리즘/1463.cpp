#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int dp[1000001];

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int ans;
	int input;
	scanf("%d", &input);
	dp[1] = 0;
	for (int i = 2; i <= input; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) {
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		}

	}
	printf("%d", dp[input]);
	return 0;
}