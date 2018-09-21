#define _CRT_SECURE_NO_WARNINGS

#define INF 2e9;
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct node {
	int stair1;
	int stair2;

}node;

int T, n, ans, person;
int d[11][11];
int stair[2][2];
node mtrx[10];
bool idx[10];
int stair_1[10];
int stair_2[10];
int stair1_leng, stair2_leng;
int stair1_in[3], stair2_in[3];

int min(int a, int b) {
	return a > b ? b : a;
}
int max(int a, int b) {
	return a > b ? a : b;
}
void pop(int *arr) {
	for (int i = 0; i < 3; i++) {
		if (i == 2) {
			arr[i] = 0;
			break;
		}
		arr[i] = arr[i + i];

	}
}
int push(int* arr, int t) {
	for (int i = 0; i < 3; i++) {
		if (arr[i] == 0) {
			arr[i] = t;
			return 1;
		}
	}
	return 0;
}

void calc_stair() {
	//for (int k = 0; k < person; k++) {
	int k = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[j][i] == 1) {
				mtrx[k].stair1 = abs(j - stair[0][0]) + abs(i - stair[0][1]);
				mtrx[k].stair2 = abs(j - stair[1][0]) + abs(i - stair[1][1]);
				k++;
			}
		}
	}
	//}
}
void timerun() {
	/*int i = 0;
	int a = 0, b = 0;
	while (i != person) {
		if (idx[i]) {
			stair_1[a] = mtrx[i].stair1+1;
			a++;
		}
		else {
			stair_2[b] = mtrx[i].stair2+1;
			b++;
		}
		i++;
	}
	int time = 0;
	bool check1 = false, check2 = false;
	int cnt_end1 = 0, cnt_end2 = 0;
	while (1) {
		for (int i = 0; i < 3; i++) {
			if (stair1_in[i] > 0)
				stair1_in[i]--;
			if (stair2_in[i] > 0)
				stair2_in[i]--;
		}
		if (a == 0) {
			check1 = true;
		}
		for (int i = 0; i < a; i++) {
			if (stair_1[i] > 0) {
				stair_1[i]--;
			}
			if (stair_1[i] == 0) {
				if (push(stair1_in, stair1_leng)) {
					stair_1[i] = -1;
					cnt_end1++;
					if (cnt_end1 == a) {
						check1 = true;
					}
				}
			}

		}
		if (b == 0) {
			check2 = true;
		}
		for (int i = 0; i < b; i++) {
			if (stair_2[i] > 0) {
				stair_2[i]--;
			}
			if (stair_2[i] == 0) {
				if (push(stair2_in, stair2_leng)) {
					stair_2[i] = -1;
					cnt_end2++;
					if (cnt_end2 == b) {
						check2 = true;
					}
				}
			}

		}
		time++;
		if (check1 && check2) {
			while (1) {
				for (int i = 0; i < 3; i++) {
					if (stair1_in[i] > 0)
						stair1_in[i]--;
					if (stair2_in[i] > 0)
						stair2_in[i]--;

				}
				time++;
				if (!stair2_in[0] && !stair2_in[1] && !stair2_in[2] &&
					!stair1_in[0] && !stair1_in[1] && !stair1_in[2]) {
					break;
				}
				
			}
			break;
		}
	}

	ans = min(ans, time);*/
	for (int i = 0; i < person; i++)
		printf("%d", idx[i]);
}

void back_track(int cnt, int point) {
	if (cnt == 0) {
		timerun();
		printf("\n");
		return;
	}
	if (point == person) {
		return;
	}
	if (cnt > 0) {
		idx[point] = true;

		back_track(cnt - 1, point + 1);
		idx[point] = false;

	}
	back_track(cnt, point + 1);

}


int main() {
	scanf("%d", &T);
	for (int k = 1; k <= T; k++) {
		scanf("%d", &n);
		ans = INF;
		bool check = false;
		person = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &d[j][i]);
				if (d[j][i] == 1) {
					person++;
				}
				if (d[j][i] != 1 && d[j][i] != 0) {
					if (check == false) {
						stair[0][0] = j;
						stair[0][1] = i;
						check = true;
						stair1_leng = d[j][i];
					}
					else {
						stair[1][0] = j;
						stair[1][1] = i;
						stair2_leng = d[j][i];
					}
				}
			}
		}
		calc_stair();
		timerun();
		for (int i = 1; i <= person; i++) {
			back_track(i, 0);
		}

		/*	for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					printf("%d", d[j][i]);
				}
				printf("\n");
			}
			for (int i = 0; i <= 1; i++) {
				for (int j = 0; j <= 1; j++) {
					printf("%d", stair[i][j]);
				}
				printf("\n");
			}*/
		printf("#%d %d\n", k, ans);
		memset(d, 0, sizeof(d));
		memset(mtrx, 0, sizeof(mtrx));
		memset(idx, 0, sizeof(idx));
		memset(stair_1, 0, sizeof(stair_1));
		memset(stair_2, 0, sizeof(stair_2));

	}
	return 0;
}