#define _CRT_SECURE_NO_WARNINGS
/*
BFS
*/
#include <iostream>	
#include <queue>
#include <stack>

using namespace std;
int n, k, visit[100001];
int chase[100001];
queue<int> q;
int bfs() {
	q.push(n);
	visit[n] = 1;

	while (!q.empty()) {
		int chk = q.front();
		q.pop();
		if (chk == k) {
			return visit[chk] - 1;
		}
		if (chk - 1 >= 0 && visit[chk - 1] == 0) {
			q.push(chk - 1);
			visit[chk-1] = visit[chk] + 1;
			chase[chk - 1] = chk;
		}
		if (chk + 1 <=100000 && visit[chk + 1] == 0) {
			q.push(chk + 1);
			visit[chk + 1] = visit[chk] + 1;
			chase[chk + 1] = chk;
		}
		if (chk*2 <= 100000 && visit[chk*2] == 0) {
			q.push(chk*2);
			visit[chk*2] = visit[chk] + 1;
			chase[chk*2] = chk;
		}
		

	}
}
int main() {
	
	scanf("%d %d", &n, &k);
	printf("%d\n", bfs());
	stack<int> ans;
	ans.push(k);
	for (int i = k; i != n; i=chase[i]) {
		ans.push(chase[i]);
	}

	while (!ans.empty()) {
		int a = ans.top();
		ans.pop();
		printf("%d ", a);
	}
	return 0;
}

