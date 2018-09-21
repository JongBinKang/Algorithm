#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector <vector<int>> v;
int indegree[10002];
vector <int> check;

int main() {
	int N;
	int time, num, ans = 0;
	vector <int> q;

	
	scanf("%d", &N);
	v.resize(N + 2);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &time, &num);
		v[i].push_back(time);
		if (num == 0) {
			q.push_back(i);
			
		}
		for (int j = 0; j < num; j++) {
			int a;
			scanf("%d", &a);
			v[a].push_back(i);
			indegree[i]++;
		}
	}
	while (!(q.empty())) {
		int tmp_time = 101;
		while (!(q.empty())) {
			int tmp;
			tmp = q.back();
			q.pop_back();
			check.push_back(tmp);
			tmp_time = min(tmp_time, v[tmp][0]);
		}
		ans += tmp_time;
		for (int i = 0; i < check.size(); i++) {
			v[check[i]][0] -= tmp_time;
			if (v[check[i]][0] == 0) {
				indegree[check[i]] = -1;
				for (int j = 1; j < v[check[i]].size(); j++) {
					int k = v[check[i]][j];
					indegree[k]--;
					
				}
			}
		}
		int a = check.size();
		for (int i = 0; i < a; i++){
			check.pop_back();
		}
		for (int i = 1; i <= N; i++) {
			if (indegree[i] == 0) {
				q.push_back(i);
			}
		}
	}
	printf("%d", ans);
}