#define _CRT_SECURE_NO_WARNINGS

/*
2018.04.18
10872�� ���丮��

����
0���� ũ�ų� ���� ���� N�� �־�����. �� ��, N!�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
�Է�
ù° �ٿ� ���� N(0 �� N �� 12)�� �־�����.
���
ù° �ٿ� N!�� ����Ѵ�.
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