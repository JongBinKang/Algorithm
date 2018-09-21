#define _CRT_SECURE_NO_WARNINGS
/*
2018.04.20
1764번 듣보잡

문제
김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.
입력
첫째 줄에 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M이 주어진다. 이어서 둘째 줄부터 N개의 줄에 걸쳐 듣도 못줄부터 보도 못한 사람의 이름이 순서대로 주어진다. 이름은 띄어쓰기 없이 영어 소문자로만 이루어지며, 그 길이는20 이하이다. N, M은 500,000 이하의 자연수이다.
출력
듣보잡의 수와 그 명단을 사전순으로 출력한다.
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