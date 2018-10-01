#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
vector<int> node[100001];
int visit[1000010];

int dfs(int s, int n);

vector<int> solution(int N, vector<vector<int>> directory, vector<vector<int>> query) {
	vector<int> answer;
	for (int i = 0; i < directory.size(); i++) {
		int a, b;
		a = directory[i][0];
		b = directory[i][1];
		node[a].push_back(b);
		node[b].push_back(a);
	}
	for (int i = 0; i <= N; i++) {
		sort(node[i].begin(), node[i].end());
	}
	dfs(4, 5);
	memset(visit, 0, sizeof(visit));
	return answer;
}
int dfs(int s, int n) {
	visit[s] = 1;
	for (int i = 0; i < node[s].size(); i++) {
		if (!visit[node[s][i]]) {
			dfs(node[s][i], n);
		}
	}
}

int main() {
	vector<vector<int>> dirc;
	vector<vector<int>> que;
	dirc.resize(5);
	dirc[0].push_back(1);
	dirc[0].push_back(2);
	dirc[1].push_back(1);
	dirc[1].push_back(3);
	dirc[2].push_back(2);
	dirc[2].push_back(4);
	dirc[3].push_back(2);
	dirc[3].push_back(5);
	
	solution(5, dirc, que);

}