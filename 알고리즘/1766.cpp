#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <vector<int>> v;
int indegree[32001];

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	v.resize(N+1);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		indegree[b]++;

	}
	priority_queue <int> q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(-i);
		}
	}
	while (!(q.empty())) {
		int tmp = -q.top();
		q.pop();
		printf("%d ", tmp);

		for (int i = 0; i < v[tmp].size(); i++) {
			int next = v[tmp][i];
			indegree[next]--;
			if (indegree[next] == 0) {
				q.push(-next);
			}

		}

	}
}