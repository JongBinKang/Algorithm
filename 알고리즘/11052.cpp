#define _CRT_SECURE_NO_WARNINGS
///*
//11052�� �ؾ �Ǹ��ϱ�
//2018.04.10
//*/
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int n;
//int num[1001];
//
//int main() {
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &num[i]);
//	}
//	for (int i = 2; i <= n; i++) {
//		for (int j = 1; j < i; j++) {
//			num[i] = num[i-j] + num[j] > num[i] ? num[i-j] + num[j] : num[i];
//		}
//	}
//	printf("%d", num[n]);
//}
#include <iostream>

using namespace std;

int dp[1001];
int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1 ; i <= n; i++) {
		scanf("%d", &dp[i]);
	}
	for (int i = 2; i <= n; i++) {
		for(int j = 1 ; j < i ; j++){
			dp[i] = max(dp[i - j] + dp[j], dp[i]);
		}
	}
	printf("%d", dp[n]);
}