#define _CRT_SECURE_NO_WARNINGS
/*

2018.04.18
1924�� 2007�� 
����

������ 2007�� 1�� 1�� �������̴�. �׷��ٸ� 2007�� x�� y���� ���� �����ϱ�? �̸� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �� ĭ�� ���̿� �ΰ� x(1��x��12)�� y(1��y��31)�� �־�����. ����� 2007�⿡�� 1, 3, 5, 7, 8, 10, 12���� 31�ϱ���, 4, 6, 9, 11���� 30�ϱ���, 2���� 28�ϱ��� �ִ�.

���
ù° �ٿ� x�� y���� ���� ���������� ���� SUN, MON, TUE, WED, THU, FRI, SAT�� �ϳ��� ����Ѵ�.

https://www.acmicpc.net/problem/1924
*/
#include <iostream>

using namespace std;

char* yoil[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int m, d;

int main() {

	int sum = 0;;
	scanf("%d %d", &m, &d);
	for (int i = 1; i <= m - 1; i++) {
		sum += month[i];
	}
	sum += d;
	sum = sum % 7;
	printf("%s", yoil[sum]);

}