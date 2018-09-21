#define _CRT_SECURE_NO_WARNINGS
/*
11052¹ø ºØ¾î»§ ÆÇ¸ÅÇÏ±â
2018.04.10
*/

#include <iostream>
#include <vector>

using namespace std;

int n;
int num[1001];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			num[i] = num[i-j] + num[j] > num[i] ? num[i-j] + num[j] : num[i];
		}
	}
	printf("%d", num[n]);
}