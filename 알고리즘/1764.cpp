#define _CRT_SECURE_NO_WARNINGS
/*
2018.04.20
1764�� �躸��

����
�������� �赵 ���� ����� ��ܰ�, ���� ���� ����� ����� �־��� ��, �赵 ���� ���� ����� ����� ���ϴ� �����׷��� �ۼ��Ͻÿ�.
�Է�
ù° �ٿ� �赵 ���� ����� �� N, ���� ���� ����� �� M�� �־�����. �̾ ��° �ٺ��� N���� �ٿ� ���� �赵 ���ٺ��� ���� ���� ����� �̸��� ������� �־�����. �̸��� ���� ���� ���� �ҹ��ڷθ� �̷������, �� ���̴�20 �����̴�. N, M�� 500,000 ������ �ڿ����̴�.
���
�躸���� ���� �� ����� ���������� ����Ѵ�.
https://www.acmicpc.net/problem/1764
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N, M;

char listen[500001][20];
char look[500001][20];
vector <string> ans;

int main() {
	scanf("%d %d", &N, &M);
	int count = 0;
	for (int i = 0; i < N; i++) {
		scanf("%s", &listen[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%s", &look[i]);
	}
	

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!strcmp(listen[j], look[i])){
				count++;
				ans.push_back(listen[j]);
			}
		}

	}
	printf("%d\n", count);

	for (int i = 0; i < count; i++) {
		printf("%s\n", ans[i].c_str());
	}
	

}