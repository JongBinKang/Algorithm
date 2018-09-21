#define _CRT_SECURE_NO_WARNINGS
/*
2018.4.20
10886�� 0 = not cute / 1 = cute

����
����� �ڱⰡ ������ �Ϳ����� ����ϰ� �ִٰ� �����Ѵ�. ������ ������ �� �� �� �ǰ��� ���� �� �߸��� �� ���Ҵ�. �׷��⿡�������縦 �Ͽ� ���� �Ϳ����� �ƴ��� �˾ƺ���� �ߴ�.
�Է�
ù ��° �ٿ� �������縦 �� ����� �� N (1 �� N �� 101, N�� Ȧ��)�� �־�����.
���� N���� �ٿ��� �� �ٸ��� �� ����� ���� ���翡 � �ǰ��� ǥ���ߴ����� ��Ÿ���� ������ �־�����. 0�� ���� �Ϳ����ʴٰ� �ߴٴ� ���̰�, 1�� ���� �Ϳ��ٰ� �ߴٴ� ���̴�.
���
���� �Ϳ��� �ʴٴ� �ǰ��� �� ���� ��� "Junhee is not cute!"�� ����ϰ� �Ϳ��ٴ� �ǰ��� ���� ��� "Junhee is cute!"��
����϶�.
https://www.acmicpc.net/problem/10886
*/

#include <iostream>

using namespace std;

int N;

const char* ans(int cute, int nocute) {
	return cute > nocute ? "Junhee is cute!" : "Junhee is not cute!";
}

int main() {
	scanf("%d", &N);
	int count_cute = 0;
	int count_nocute = 0;
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		if (a) {
			count_cute++;
		}
		else
			count_nocute++;
	}
	printf("%s",ans(count_cute, count_nocute));
	return 0;
}