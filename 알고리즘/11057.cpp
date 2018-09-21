#define _CRT_SECURE_NO_WARNINGS
/*
11057번 오르막 수
2018.04.11
*/

#include <iostream>
#define mod 10007;
using namespace std;

int dp[1001][10];
int n,sum=0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i < n + 1; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0){
				dp[i][j] = 1;
				continue;
			}
				for (int k = 0; k <= j; k++)
			dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod ;
		}
	}
	for (int i = 0; i < 10; i++)
		sum = (sum + dp[n][i]) % mod;

	printf("%d", sum);

}