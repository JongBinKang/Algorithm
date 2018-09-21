#define _CRT_SECURE_NO_WARNINGS
#define BIG 2e9;

#include <iostream>
#include <math.h>

using namespace std;

int T,ans;
int S[17][17];
int check[17];


void recursion(int N, int cnt, int food_num) {

	if (cnt == N) {
		int s1=0, s2=0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j)
					continue;
				if (check[i] && check[j])
					s1 += S[i][j];
				if (!check[i] && !check[j])
					s2 += S[i][j];
			}
		}
		ans = fmin(ans, abs(s1-s2));
		return;
	}

	if (food_num > 0) {
		check[cnt] = true;
		recursion(N, cnt + 1, food_num - 1);
		check[cnt] = false;
	}

	recursion(N, cnt + 1, food_num);

}


int main() {
	scanf("%d", &T);
	for(int k = 1; k < T+1 ; k++){
		int n;
		scanf("%d", &n);
		for (int i = 1; i < n+1; i++) {
			for (int j = 1; j < n + 1; j++) {
				scanf("%d", &S[i][j]);
			}
		}
		ans = BIG;
		recursion(n, 0, n / 2);
		printf("#%d %d", k, ans);
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				S[i][j] = 0;
			}
		}
		
	}
	

}