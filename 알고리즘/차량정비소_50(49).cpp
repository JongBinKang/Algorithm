#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
#include <string.h>

using namespace std;
int T, ans[1001][2];
int N, M, K, A, B;
int a[10], b[10];
int visiter[1001];
int repair[10][2], reception[10][2];
queue <int> waiting;
int idx = 1;
void timerun() {
	
	for (int i = 1; i <= K; i++) {
		if (visiter[i] > 0) {
			visiter[i]--;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (reception[i][0] > 0)
			reception[i][0]--;
		if (reception[i][0] == 0 ) {
			if(reception[i][1])
				waiting.push(reception[i][1]);
			reception[i][1] = 0;
			for (int j = 1; j <= K; j++) {
				if (visiter[j] == 0) {
					reception[i][0] = a[i];
					reception[i][1] = j;
					ans[j][0] = i;
					visiter[j] = -2;
					idx++;
					break;
				}
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		if (repair[i][0] > 0) {
			repair[i][0]--;
		}
		if (repair[i][0] == 0) {
			repair[i][1] = 0;
			if (!(waiting.empty())) {
				int tmp = waiting.front();
				waiting.pop();
				ans[tmp][1] = i;
				repair[i][0] = b[i];
				visiter[tmp] = -1;
			}


		}
	}


	

}

int main() {

	scanf("%d", &T);
	for (int k = 1; k <= T; k++) {
		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= M; i++) {
			scanf("%d", &b[i]);
		}
		for (int i = 1; i <= K; i++) {
			scanf("%d", &visiter[i]);

			visiter[i]++;
		}
		idx = 1;
		bool check = false;;
		while (1) {
			timerun();
			for (int j = 1; j <= K; j++) {
				if (visiter[j] != -1) {
					break;
				}
				if (j == K) {
					check = true;
				}
			}
			if (check) {
				break;
			}
			for (int j = 1; j <= N; j++) {
				if (visiter[K] == -2) {
					break;
				}
				if (visiter[idx] == 0) {
						if (reception[j][0] == 0) {
							reception[j][0] = a[j];
							reception[j][1] = idx;
							ans[idx][0] = j;
							visiter[idx] = -2;
							idx++;
							
						}
					}
			}			
			

		}
		int sum = 0;
		for (int i = 1; i <= K; i++) {
			if (ans[i][0] == A && ans[i][1] == B) {
				sum += i;
				
			}
			//printf("%d %d %d\n", i, ans[i][0], ans[i][1]);
		}
		if (sum == 0) {
			sum = -1;
		}
		printf("#%d %d\n", k, sum);
		memset(ans, 0, sizeof(ans));
	
		memset(visiter, 0, sizeof(visiter));
		memset(reception, 0, sizeof(reception));
		memset(repair, 0, sizeof(repair));
		while(!(waiting.empty())){
		waiting.pop();
		}
	}
}