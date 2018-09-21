#define _CRT_SECURE_NO_WARNINGS
/*
2018.04.20
2960�� �����佺�׳׽��� ü

����
�����佺�׳׽��� ü�� N���� �۰ų� ���� ��� �Ҽ��� ã�� ������ �˰����̴�.�� �˰����� ������ ����.2���� N���� ��� ������ ���´�.���� ������ ���� ���� �� ���� ���� ���� ã�´�. �̰��� P��� �ϰ�, �� ���� �Ҽ��̴�.P�� �����, ���� ������ ���� P�� ����� ũ�� ������� �����.���� ��� ���ڸ� ������ �ʾҴٸ�, �ٽ� 2�� �ܰ�� ����.N, K�� �־����� ��, K��° ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �־�����. (1 �� K < N, max(2, K) < N �� 1000)
���
ù° �ٿ� K��° ������ ���� ����Ѵ�.
*/

#include <iostream>	
#include <math.h>

using namespace std;

int N, K;
int sosu[1001];
int count1 = 0;


void make_sosu(int n) {
	for (int i = 1; i*n <= N; i++) {
		if(sosu[i*n] != 1){
			sosu[i*n] = 1;
			count1++;
		}
		if (count1 == K){
			printf("%d", i*n);
				break;
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);
	
	for (int i = 2; i <= N; i++) {
		if (sosu[i] == 0){
			make_sosu(i);
			if (count1 == K)
				break;
		}
	}
}