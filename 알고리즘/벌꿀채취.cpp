#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int T, ans = -1, N, M, C;
int honey[10][10];
bool visited[10][10];
int tmp;
int _max;
bool sex;
void find_max(int x, int y, int cnt, int sum, int nowmax) {
	if (honey[x][y] + sum <= C) {
		sum = sum + honey[x][y];
		nowmax += pow(honey[x][y], 2);
		_max = fmax(_max, nowmax);
		for (int i = 1; i < cnt; i++) {
			find_max(x + i, y, cnt - i, sum, nowmax);

		}
	}
	else
		return;

}

void dfs(int x, int y) {

	for (int j = y; j < N; j++) {
		for (int i = x; i < N - M + 1; i++) {
			tmp = 0;
			_max = 0;
			for (int k = 0; k < M; k++) {
				find_max(i + k, j, M - k, 0, 0);
				visited[i + k][j] = true;
			}

			tmp = _max;
			for (int k = j; k < N; k++) {
				for (int l = x; l < N - M + 1; l++) {
					bool check= false;
					for (int p = 0; p < M; p++) {
						if (visited[l + p][k]) {
							check = true;
						}
					}
					if (!check) {
						int tmp1 = 0;
						_max = 0;
						for (int p = 0; p < M; p++) {
							find_max(l + p, k, M - p, 0, 0);
						}
						tmp1 = _max;
						ans = fmax(ans, tmp + tmp1);
						if (ans == 264 && !sex) {
							sex = true;
							printf("%d %d %d %d", i,j,l,k);
						}
					
					}
				}
			}
			for (int k = 0; k < M; k++) {
				visited[i + k][j] = false;
			}

		}
	}

}

int main() {
	scanf("%d", &T);
	for (int k = 1; k <= T; k++) {
		scanf("%d %d %d", &N, &M, &C);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &honey[j][i]);
			}
		}
		ans = 0;
		dfs(0, 0);
		memset(honey, 0, sizeof(honey));
		memset(visited, 0, sizeof(visited));
		printf("#%d %d\n", k, ans);
	}
	return 0;
}