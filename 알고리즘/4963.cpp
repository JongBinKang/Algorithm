#define _CRT_SECURE_NO_WARNINGS
/*
2018.04.10
4963¹ø ¼¶ÀÇ °³¼ö

*/

#include<iostream>
#include <vector>


using namespace std;
const int dx[] = { 1,1,1,-1,-1,-1,0,0 };
const int dy[] = { 0,1,-1,0,1,-1,1,-1, };
int island[51][51], w, h, cnt;
int visited[51][51];


void dfs(int, int);

int main() {
	while (1) {
		cnt = 0;
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &island[i][j]);
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (visited[i][j] == false && island[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}
	
		printf("%d\n", cnt);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				visited[i][j] = 0;
				island[i][j] = 0;
			}
		}

	}

}
void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= h || ny < 0 || ny >= w)
			continue;
		if (visited[nx][ny] == 0 && island[nx][ny] == 1)
			dfs(nx, ny);
	}
}