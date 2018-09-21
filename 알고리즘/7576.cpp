#define _CRT_SECURE_NO_WARNINGS
/*
7576번 토마토
2018.04.10
큐로 풀어야한다!
*/
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
typedef struct node {
	int x;
	int y;
	int cnt;
	node(int _x, int _y, int _cnt) : x(_x), y(_y), cnt(_cnt) {}

}node;



const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };

int tomato[1001][1001], sum[1001][1001];
bool visited[1001][1001];
int m, n, day = 0;
int cnt_full = 0, cnt_empty = 0;
bool chk_not;
queue<node> q;


int bfs();

int main() {

	scanf("%d %d", &m, &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1) {
				cnt_full++;
			}
			else if (tomato[i][j] == -1) {
				cnt_empty++;
			}
		}
	}

	if (cnt_full == m*n || cnt_empty == m*n)
		printf("0");
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tomato[i][j] == 1 && !visited[i][j]) {
					q.push(node(i, j, 0));
				}
			}
		}
		int ans = bfs();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tomato[i][j] == 0) {
					printf("-1\n");
					chk_not = true;
					break;
				}
			}
			if (chk_not)
				break;
		}
		if(!chk_not)
			printf("%d\n", ans);
	}




}
int bfs() {
	int x = 0, y = 0;
	while (!(q.empty())) {
		node now = q.front();
		day = day < now.cnt ? now.cnt : day;
		x = now.x;
		y = now.y;

		q.pop();
		visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || tomato[nx][ny] == -1 || tomato[nx][ny] == 1)
				continue;
			q.push(node(nx, ny, day + 1));
			tomato[nx][ny] = 1;

		}
	}
	return day;
}
