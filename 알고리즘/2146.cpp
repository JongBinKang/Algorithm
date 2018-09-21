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
	node(int _x, int _y) : x(_x), y(_y) {}

}node;



const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };

int island[101][101], leng_map[101][101];
bool visited[101][101];
int n, length = -1;
bool chk_not;
queue<node> q;


void numbering_bfs(int,int,int);
int extend_bfs();

int main() {

	scanf("%d", &n);
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &island[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (island[i][j] == 1 && !visited[i][j]) {
				numbering_bfs(i, j, cnt);
				cnt++;
			}
		}
	}
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (island[i][j] != 0 ) {
				leng_map[i][j] = 1;
				q.push(node(i, j));
			}
		}
	}

	printf("%d", extend_bfs()-2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", leng_map[i][j]);	
			
		}
		printf("\n");
	}

	
}
int extend_bfs() {
	while(!(q.empty())){
		node now = q.front();
		int x = now.x;
		int y = now.y;
		q.pop();
		visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (island[nx][ny] != 0 && island[nx][ny] != island[x][y]) {
				int tmp = leng_map[x][y] + leng_map[nx][ny];
				if (length > tmp || length == -1)
					length = tmp;
			}

			if (island[nx][ny] == 0) {
				q.push(node(nx, ny));
				island[nx][ny] = island[x][y];
				leng_map[nx][ny] = leng_map[x][y]+1;
			}
		}
	}
	return length;
}
void numbering_bfs(int x,int y,int idx) {
	queue<node> nq;
	nq.push(node(x, y));
	visited[x][y] = true;
	while (!(nq.empty())) {
		node now = nq.front();
		x = now.x;
		y = now.y;
		nq.pop();
		island[x][y] = idx;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || island[nx][ny] == 0 || visited[nx][ny])
				continue;
			nq.push(node(nx, ny));
			visited[nx][ny] = true;
			island[nx][ny] = idx;
		}
	}

}

