#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

typedef struct node {
	int x;
	int y;
	int cnt;
	node(int _x, int _y,int _cnt) : x(_x), y(_y), cnt(_cnt){}
}node;

int T, ans;
int tunnel[51][51], N, M, R, C, L;
bool visited[51][51];

void bfs(int count, int x, int y) {
	queue <node> q;
	q.push(node(x, y,1));
	visited[x][y] = true;
	while (!(q.empty())) {
		node tmp = q.front();
		if(tmp.cnt == count)
			break;
		int x = tmp.x;
		int y = tmp.y;
		int n = tmp.cnt;
		q.pop();
		if (tunnel[x][y] == 1) {
			if (x + 1 < M && !visited[x + 1][y] && tunnel[x + 1][y] && tunnel[x + 1][y] != 4 && tunnel[x + 1][y] != 5 && tunnel[x + 1][y] != 2) {
				visited[x + 1][y] = true;
				q.push(node(x + 1, y,n+1));
			}
			if (y - 1 >= 0 && !visited[x][y - 1] && tunnel[x][y - 1] && tunnel[x][y - 1] != 3 && tunnel[x][y - 1] != 4 && tunnel[x][y - 1] != 7) {
				visited[x][y - 1] = true;
				q.push(node(x, y - 1, n + 1));
			}
			if (y + 1 < N && !visited[x][y + 1] && tunnel[x][y + 1] && tunnel[x][y + 1] != 3 && tunnel[x][y + 1] != 5 && tunnel[x][y + 1] != 6) {
				visited[x][y + 1] = true;
				q.push(node(x, y + 1, n + 1));
			}
			if (x - 1 >= 0 && !visited[x - 1][y] && tunnel[x - 1][y] && tunnel[x - 1][y] != 2 && tunnel[x - 1][y] != 6 && tunnel[x - 1][y] != 7) {
				visited[x - 1][y] = true;
				q.push(node(x - 1, y, n + 1));
			}
		}
		if (tunnel[x][y] == 2) {
			if (y - 1 >= 0 && !visited[x][y - 1] && tunnel[x][y - 1] && tunnel[x][y - 1] != 3 && tunnel[x][y - 1] != 4 && tunnel[x][y - 1] != 7) {
				visited[x][y - 1] = true;
				q.push(node(x, y - 1, n + 1));
			}
			if (y + 1 < N && !visited[x][y + 1] && tunnel[x][y + 1] && tunnel[x][y + 1] != 3 && tunnel[x][y + 1] != 5 && tunnel[x][y + 1] != 6) {
				visited[x][y + 1] = true;
				q.push(node(x, y + 1, n + 1));
			}

		}
		if (tunnel[x][y] == 3) {
			if (x + 1 < M && !visited[x + 1][y] && tunnel[x + 1][y] && tunnel[x + 1][y] != 4 && tunnel[x + 1][y] != 5 && tunnel[x + 1][y] != 2) {
				visited[x + 1][y] = true;
				q.push(node(x + 1, y, n + 1));
			}

			if (x - 1 >= 0 && !visited[x - 1][y] && tunnel[x - 1][y] && tunnel[x - 1][y] != 2 && tunnel[x - 1][y] != 6 && tunnel[x - 1][y] != 7) {
				visited[x - 1][y] = true;
				q.push(node(x - 1, y, n + 1));
			}

		}
		if (tunnel[x][y] == 4) {
			if (x + 1 < M && !visited[x + 1][y] && tunnel[x + 1][y] && tunnel[x + 1][y] != 4 && tunnel[x + 1][y] != 5 && tunnel[x + 1][y] != 2) {
				visited[x + 1][y] = true;
				q.push(node(x + 1, y, n + 1));
			}
			if (y - 1 >= 0 && !visited[x][y - 1] && tunnel[x][y - 1] && tunnel[x][y - 1] != 3 && tunnel[x][y - 1] != 4 && tunnel[x][y - 1] != 7) {
				visited[x][y - 1] = true;
				q.push(node(x, y - 1, n + 1));
			}


		}
		if (tunnel[x][y] == 5) {
			if (x + 1 < M && !visited[x + 1][y] && tunnel[x + 1][y] && tunnel[x + 1][y] != 4 && tunnel[x + 1][y] != 5 && tunnel[x + 1][y] != 2) {
				visited[x + 1][y] = true;
				q.push(node(x + 1, y, n + 1));
			}

			if (y + 1 < N && !visited[x][y + 1] && tunnel[x][y + 1] && tunnel[x][y + 1] != 3 && tunnel[x][y + 1] != 5 && tunnel[x][y + 1] != 6) {
				visited[x][y + 1] = true;
				q.push(node(x, y + 1, n + 1));
			}


		}
		if (tunnel[x][y] == 6) {

			if (y + 1 < N && !visited[x][y + 1] && tunnel[x][y + 1] && tunnel[x][y + 1] != 3 && tunnel[x][y + 1] != 5 && tunnel[x][y + 1] != 6) {
				visited[x][y + 1] = true;
				q.push(node(x, y + 1, n + 1));
			}
			if (x - 1 >= 0 && !visited[x - 1][y] && tunnel[x - 1][y] && tunnel[x - 1][y] != 2 && tunnel[x - 1][y] != 6 && tunnel[x - 1][y] != 7) {
				visited[x - 1][y] = true;
				q.push(node(x - 1, y, n + 1));
			}

		}
		if (tunnel[x][y] == 7) {

			if (y - 1 >= 0 && !visited[x][y - 1] && tunnel[x][y - 1] && tunnel[x][y - 1] != 3 && tunnel[x][y - 1] != 4 && tunnel[x][y - 1] != 7) {
				visited[x][y - 1] = true;
				q.push(node(x, y - 1, n + 1));
			}

			if (x - 1 >= 0 && !visited[x - 1][y] && tunnel[x - 1][y] && tunnel[x - 1][y] != 2 && tunnel[x - 1][y] != 6 && tunnel[x - 1][y] != 7) {
				visited[x - 1][y] = true;
				q.push(node(x - 1, y, n + 1));
			}
		}

	}


}

int main() {
	scanf("%d", &T);
	for (int k = 1; k <= T; k++) {
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &tunnel[j][i]);
			}
		}



		bfs(L, C, R);
		ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf("%d", visited[j][i]);
				if (visited[j][i]) {
					ans++;
				}
			}
			printf("\n");
		}
		memset(tunnel, 0, sizeof(tunnel));
		memset(visited, 0, sizeof(visited));
		printf("#%d %d\n", k, ans);
	}
}