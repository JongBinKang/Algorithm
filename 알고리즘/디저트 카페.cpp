#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int T,ans;
int cafe[21][21];
int dx[4] = { 1,-1,1 ,-1 }; // ¿À¾Æ·¡, ¿Þ¾Æ·¡, ¿ÀÀ§, ¿ÞÀ§
int dy[4] = { 1, 1,-1,-1 };
bool dessert[101];
int idx;
int n, i_x, i_y;

void recursion(int idx, bool check[101],int x,int y) {
	if (x == n && y == n)
		return;
	if (x == 0 && y ==  n)
		return;
	if (x == 0 && y == 0)
		return;
	if (x == n && y == 0)
		return;

	int nx, ny;
	if (idx == -1) {
		nx = x + dx[0];
		ny = y + dy[0];
		if (nx >= n)
			return;
		dessert[cafe[x][y]] = true;	
		recursion(0, check, x + dx[0], y + dy[0]);
		dessert[cafe[x][y]] = false;
	}
	if (idx == 0) {
		if (dessert[cafe[x][y]])
			return;
		dessert[cafe[x][y]] = true;
		nx = x + dx[0]; ny = y + dy[0];
		if(nx >= 0 && ny>=0 && nx<n && ny<n)
			recursion(0, check, x + dx[0], y + dy[0]);
		nx = x + dx[1]; ny = y + dy[1];
		if (nx >= 0 && ny >= 0 && nx<n && ny<n)
			recursion(1, check, x + dx[1], y + dy[1]);

		dessert[cafe[x][y]] = false;
	}
	if (idx == 1) {
		if (dessert[cafe[x][y]])
			return;
		dessert[cafe[x][y]] = true;
		nx = x + dx[1]; ny = y + dy[1];
		if (nx >= 0 && ny >= 0 && nx<n && ny<n)
			recursion(1, check, x + dx[1], y + dy[1]);
		nx = x + dx[3]; ny = y + dy[3];
		if (nx >= 0 && ny >= 0 && nx<n && ny<n)
			recursion(3, check, x + dx[3], y + dy[3]);

		dessert[cafe[x][y]] = false;
	}
	if (idx == 2) {
		if (dessert[cafe[x][y]] && i_x == x && i_y == y) {
			int cnt = 0;
			for (int i = 1; i <= 100; i++) {
				if (check[i])
					cnt++;
			}
			ans = fmax(ans, cnt);
			return;
		}
		if (dessert[cafe[x][y]])
			return;
		dessert[cafe[x][y]] = true;
		nx = x + dx[2]; ny = y + dy[2];
		if (nx >= 0 && ny >= 0 && nx<n && ny<n)
			recursion(2, check, x + dx[2], y + dy[2]);

		dessert[cafe[x][y]] = false;
		
	}
	if (idx == 3) {
		if (dessert[cafe[x][y]])
			return;
		dessert[cafe[x][y]] = true;
		nx = x + dx[3]; ny = y + dy[3];
		if (nx >= 0 && ny >= 0 && nx<n && ny<n)
			recursion(3, check, x + dx[3], y + dy[3]);
		nx = x + dx[2]; ny = y + dy[2];
		if (nx >= 0 && ny >= 0 && nx<n && ny<n)
			recursion(2, check, x + dx[2], y + dy[2]);

		dessert[cafe[x][y]] = false;
	}

}

int main() {
	scanf("%d", &T);
	for (int k = 1; k <= T; k++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &cafe[j][i]);
			}
		}
		ans = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				i_x = j;
				i_y = i;
				recursion(-1, dessert, j, i);
			}
		}
		memset(cafe, 0, sizeof(cafe));
		memset(dessert, 0, sizeof(dessert));
		printf("#%d %d\n", k, ans);
	}

	return 0;
}

