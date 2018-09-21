#define _CRT_SECURE_NO_WARNINGS\
/*
2178¹ø ¹Ì·Î Å½»ö
2018.04.10
*/

#include <iostream>
#include <string.h>

using namespace std;

const int dx[] = { 1, -1 , 0, 0 };
const int dy[] = { 0 , 0, 1, -1 };
int miro[101][101];
int sum[101][101];
bool visited[101][101];
int n, m;

void dfs(int, int);

int main() {
	
	memset(sum, -1, sizeof(sum));
	sum[0][0] = 1;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &miro[i][j]);
		}
	}
	dfs(0, 0);
	printf("%d", sum[n - 1][m - 1]);
}

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int tmp;
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		if (miro[nx][ny] == 1) {
			tmp = miro[nx][ny] + sum[x][y];
			if (sum[nx][ny] > tmp || sum[nx][ny] == -1){
				sum[nx][ny] = tmp;
				dfs(nx, ny);
			}
			
		}

	}
}