#define _CRT_SECURE_NO_WARNINGS
/*
10844번 쉬운 계단수
2018.04.11
*/
#define mod 1000000000;
#include<iostream>
#include <vector>

using namespace std;

int n, sum=0;
int dp[102][10];
int main() {
	scanf("%d", &n);
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i < n+1; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0){
				dp[i][j] = dp[i - 1][j + 1] % mod;
			}
			else if( j== 9){
				dp[i][j] = dp[i - 1][j - 1] % mod;
			}
			else
			    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
		}
	}
	for (int i = 0; i < 10; i++)
		sum = (sum + dp[n][i]) % mod;

	printf("%d", sum );
}