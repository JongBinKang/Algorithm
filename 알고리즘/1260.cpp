#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>	

using namespace std;

vector <int> node[1001];
int visit[1001];

void bfs(int);
void dfs(int);

int main() {
	int node_num, edge_num, start;
	scanf("%d %d %d", &node_num, &edge_num, &start);
	for (int i = 0; i < edge_num; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		node[a].push_back(b);
		node[b].push_back(a);
	}
	for (int i = 0; i < node_num; i++) {
		sort(node[i].begin(), node[i].end());
	}
	dfs(start);

	memset(visit, 0, sizeof(visit));
	bfs(start);

	return 0;
}

void dfs(int s) {
	visit[s] = 1;
	printf("%d ", s);
	for (int i = 0; i < node[s].size(); i++) {
		if (!visit[node[s][i]]) {
			dfs(node[s][i]);
		}
	}
}
void bfs(int s) {
	queue <int> q;
	q.push(s);
	
	
	while (!(q.empty())) {
		int tmp = q.front();
		printf("%d ", tmp);
		visit[tmp] = 1;
		q.pop();
		for (int i = 0; i < node[tmp].size(); i++) {
			if (!visit[node[tmp][i]]) {
				q.push(node[tmp][i]);
				visit[node[tmp][i]] = true;
			}
		}
	}
}
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//vector <int> node[1001];
//int visit[1001];
//
//void dfs(int);
//void bfs(int);
//
//int main() {
//	int vertex_num, edge_num, start;
//	scanf("%d %d %d", &vertex_num, &edge_num, &start);
//	for (int i = 0; i < edge_num; i++) {
//		int a, b;
//		scanf("%d %d", &a, &b);
//		node[a].push_back(b);
//		node[b].push_back(a);
//	}
//	for (int i = 0; i < vertex_num; i++) {
//		sort(node[i].begin(), node[i].end());
//	}
//	dfs(start);
//	memset(visit, 0, sizeof(visit));
//	printf("\n");
//	bfs(start);
//	return 0;
//
//}
//
//void dfs(int s) {
//	printf("%d ", s);
//	visit[s] = true;
//	for (int i = 0; i < node[s].size(); i++) {
//		if (!visit[node[s][i]])
//			dfs(node[s][i]);
//	}
//}
//
//void bfs(int s) {
//	queue <int> q;
//	q.push(s);
//	while (!(q.empty())) {
//		int tmp = q.front();
//		printf("%d ", tmp);
//		visit[tmp] = true;
//		q.pop();
//		for (int i = 0; i < node[tmp].size(); i++) {
//			if (!visit[node[tmp][i]]){
//				visit[node[tmp][i]] = true;
//				q.push(node[tmp][i]);
//			}
//		}
//	}
//
//}