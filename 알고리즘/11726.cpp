#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int dp[1001];

int main() {
	dp[1] = 1;
	dp[2] = 2;
	int input;
	scanf("%d", &input);

	for (int i = 3; i <= input; i++) {
		dp[i] = dp[i - 2] +dp[i - 1];
		dp[i] = dp[i] % 10007;
	}

	printf("%d", dp[input]);
	return 0;
}