#define _CRT_SECURE_NO_WARNINGS

/*

2018.04.18
9498�� ���輺��
����
���� ������ �Է¹޾� 90 ~ 100���� A, 80 ~ 89���� B, 70 ~ 79���� C, 60 ~ 69���� D, ������ ������ F�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
�Է�
ù° �ٿ� ���� ������ �־�����. ���� ������ 0���� ũ�ų� ����, 100���� �۰ų� ���� �ڿ����̴�.
���
���� ������ ����Ѵ�.
https://www.acmicpc.net/problem/9498

*/

#include <iostream>

using namespace std;

char* grade[12] = { "F","F","F","F","F","F","D","C","B","A","A" };

int main() {
	int score;
	scanf("%d", &score);
	score = score / 10;
	printf("%s", grade[score]);

}