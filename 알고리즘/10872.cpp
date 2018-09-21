#define _CRT_SECURE_NO_WARNINGS

/*
2018.04.18
10872번 팩토리얼

문제
0보다 크거나 같은 정수 N이 주어진다. 이 때, N!을 출력하는 프로그램을 작성하시오.
입력
첫째 줄에 정수 N(0 ≤ N ≤ 12)가 주어진다.
출력
첫째 줄에 N!을 출력한다.
https://www.acmicpc.net/problem/10872
*/

#include <iostream>
#include<algorithm>

int fac(int n) {
	if (n == 1) {
		return 1;
	}
	else
		return n * fac(n - 1);
}

int num;

int main() {
	int sum = 1;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		sum *= i;
	}
	printf("%d",sum);

	return 0;
}