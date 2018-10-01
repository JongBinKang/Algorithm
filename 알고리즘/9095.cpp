#define _CRT_SECURE_NO_WARNINGS

#include <iostream>	

using namespace std;
int dp[11];
int main() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	int tmp;
	scanf("%d", &tmp);
	for(int j = 0 ; j < tmp ; j++){
		int input;
		scanf("%d", &input);
		for (int i =4; i <= input; i++) {
			dp[i] = dp[i - 3] + dp[i - 2]  + dp[i - 1] ;
		}
		printf("%d\n", dp[input]);
	}
	return 0;
}
