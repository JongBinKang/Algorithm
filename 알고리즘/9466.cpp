#define _CRT_SECURE_NO_WARNINGS

/*
2018.04.10
9446�� ��������Ʈ
*/

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<int> node;
int cnt;
bool visited[100000], finished[100000];

void dfs(int curr) {
	visited[curr] = true;
	int next = node[curr];
	if (visited[next]) { //visited�� ���̰� finished�� �����϶� ����Ŭ �߻� 
		if (!finished[next]) {
			for (int tmp = next; tmp != curr; tmp = node[tmp]) //�ڱ��ڽ��� ���������� �ѹ��� Ž���ϸ鼭 cnt ++
				cnt++;
			cnt++;
		}
	}
	else dfs(next);
	finished[curr] = true; //Ž���� �ٳ����� �ڱ��ڽ����� ���ƿ��� finished ������ ����
}
int main() {
	int test_case;
	scanf("%d", &test_case);

	for (int test = 0; test < test_case; test++) {
		int ans = 0;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			node.push_back(a - 1);
		}
		fill(visited, visited + n, false);
		fill(finished, finished + n, false);
		cnt = 0;
		for (int i = 0; i < n; i++) {
			if (!visited[i])
				dfs(i);
		}
		printf("%d\n", n - cnt);
		memset(visited, 0, sizeof(visited));
		memset(finished, 0, sizeof(finished));
		for (int i = 0; i < n; i++)
			node.pop_back();

	}
}
