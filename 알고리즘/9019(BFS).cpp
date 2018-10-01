#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;


int visit[10001];
int parent[10001];
char ans[10001];
int D(int s) {
	return (s * 2) % 10000;
}
int S(int s) {
	return s - 1 <0 ? 9999 : s - 1;
}
int L(int s) {
	int a, b, c, d,tmp;
	a = s%10;
	tmp = s / 10;
	b = tmp % 10;
	tmp = tmp / 10;
	c = tmp % 10;
	tmp = tmp / 10;
	d = tmp % 10;
	return (((c * 10 + b) * 10 + a) * 10) + d;
}
int R(int s) {
	int a, b, c, d, tmp;
	a = s % 10;
	tmp = s / 10;
	b = tmp % 10;
	tmp = tmp / 10;
	c = tmp % 10;
	tmp = tmp / 10;
	d = tmp % 10;
	return (((a * 10 + d) * 10 + c) * 10) + b;
}
void bfs(int a, int b) {
	queue<int> q;
	q.push(a);
	visit[a] = 1;
	while (!q.empty()) {
		int chk = q.front();
		q.pop();
		if (chk == b) {
			return;
		}
		if(!visit[D(chk)] && parent[D(chk)]==0){
			q.push(D(chk));
			visit[D(chk)] = 1;
			ans[D(chk)] = 'D';
			parent[D(chk)] = chk;
		}
		if (!visit[S(chk)] && parent[S(chk)] == 0) {
			q.push(S(chk)); 
			visit[S(chk)] = 1;
			ans[S(chk)] = 'S';
			parent[S(chk)] = chk;
		}
		if (!visit[L(chk)] && parent[L(chk)] == 0) {
			q.push(L(chk));
			visit[L(chk)] = 1;
			ans[L(chk)] = 'L';
			parent[L(chk)] = chk;
		}
		if (!visit[R(chk)] && parent[R(chk)] == 0){
			q.push(R(chk));
			visit[R(chk)] = 1;
			ans[R(chk)] = 'R';
			parent[R(chk)] = chk;
		}
	}
}
int main() {

	int T;
	scanf("%d", &T);
	for (int k = 0; k < T; k++) {
		memset(visit, 0, sizeof(visit));
		memset(parent, 0, sizeof(parent));
		memset(ans, 0, sizeof(ans));
		int A, B;
		stack<char> dslr;
		scanf("%d %d", &A, &B);
		bfs(A,B);
		for (int i = B; i != A; i = parent[i]) {
			dslr.push(ans[i]);
	
		}
		dslr.push(ans[A]);
		dslr.pop();
		while (!dslr.empty()) {
			char a = dslr.top();
			dslr.pop();
			printf("%c", a);
		}
		printf("\n");
	}

	return 0;
}