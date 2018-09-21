#define _CRT_SECURE_NO_WARNINGS
/*
2018.04.10
2667번 단지 번호 붙이기
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[26][26];
int visited[26][26];
int k,map_size, cnt[26 * 26];
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1}; //우,좌,위,아래

void dfs(int, int);

int main() {

	k = 0;
	scanf("%d", &map_size);
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			scanf("%1d", &map[i][j]);
		}

	}
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
		
			if (visited[i][j] == false && map[i][j] == 1) {
				dfs(i,j);
				k++;
			}
		}
		
	}
	printf("%d\n", k);
	vector<int> count (cnt, cnt + k);
	sort(cnt, cnt+k);
	for (int i = 0; i < k; i++) {
		printf("%d\n", cnt[i]);
	}
}

void dfs(int x, int y) {
	visited[x][y] = true;
	cnt[k]++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx > map_size || ny < 0 || ny>map_size)
			continue;
		if (map[nx][ny] == 1 && visited[nx][ny] == false)
			dfs(nx, ny);

	}

}