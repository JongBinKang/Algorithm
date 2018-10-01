#define _CRT_SECURE_NO_WARNINGS

#include <iostream>	
#include <queue>

using namespace std;

struct node {
	int screen;
	int clip;
	int depth;
};

int n;
int visit[2001][2001];

void bfs() {
	queue<int> q;
	node root;
	root.screen = 1;
	root.clip = 0;
	root.depth = 0;

	q.push()
}
int main() {
	scanf("%d", &n);
	bfs();
	printf("%d", visit[n]);
}