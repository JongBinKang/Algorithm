#define _CRT_SECURE_NO_WARNINGS
/*
2018.04.20
1789�� ������ ��

����
���� �ٸ� N���� �ڿ����� ���� S��� �Ѵ�. S�� �� ��, �ڿ��� N�� �ִ밪�� ���ϱ�?
�Է�
ù° �ٿ� �ڿ��� S(1��S��4,294,967,295)�� �־�����.
���
ù° �ٿ� �ڿ��� N�� �ִ밪�� ����Ѵ�.
https://www.acmicpc.net/problem/1789
*/

#include <iostream>

using namespace std;

long long N;

int main() {
	
	scanf("%lld", &N);
	long long count = 0;
	long long sum = 0;
	for (long long i = 1; i <= N; i++) {
		sum += i;
		//printf("%d ", i);
		if (sum > N)
			break;
		else
			count++;
	}
	printf("%lld", count);
	return 0;
}

